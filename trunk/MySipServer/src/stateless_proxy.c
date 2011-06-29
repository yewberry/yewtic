#define THIS_FILE   "stateless_proxy.c"
#include "common.h"
#include "proxy.h"
#include "stateless_proxy.h"

/* Common proxy functions */
#define STATEFUL    0

extern struct global_struct global;

/* Callback to be called to handle incoming requests. */
static pj_bool_t on_rx_request( pjsip_rx_data *rdata );

/* Callback to be called to handle incoming response. */
static pj_bool_t on_rx_response( pjsip_rx_data *rdata );


static pj_status_t init_stateless_proxy(void)
{
    static pjsip_module mod_stateless_proxy =
    {
	NULL, NULL,			    /* prev, next.	*/
	{ "mod-stateless-proxy", 19 },	    /* Name.		*/
	-1,				    /* Id		*/
	PJSIP_MOD_PRIORITY_UA_PROXY_LAYER,  /* Priority		*/
	NULL,				    /* load()		*/
	NULL,				    /* start()		*/
	NULL,				    /* stop()		*/
	NULL,				    /* unload()		*/
	&on_rx_request,			    /* on_rx_request()	*/
	&on_rx_response,		    /* on_rx_response()	*/
	NULL,				    /* on_tx_request.	*/
	NULL,				    /* on_tx_response()	*/
	NULL,				    /* on_tsx_state()	*/
    };

    pj_status_t status;

    /* Register our module to receive incoming requests. */
    status = pjsip_endpt_register_module( global.endpt, &mod_stateless_proxy);
    PJ_ASSERT_RETURN(status == PJ_SUCCESS, 1);

    return PJ_SUCCESS;
}


/* Callback to be called to handle incoming requests. */
static pj_bool_t on_rx_request( pjsip_rx_data *rdata )
{
    pjsip_tx_data *tdata;
    pj_status_t status;


    /* Verify incoming request */
    status = proxy_verify_request(rdata);
    if (status != PJ_SUCCESS) {
		app_perror("RX invalid request", status);
		return PJ_TRUE;
    }

    /*
     * Request looks sane, next clone the request to create transmit data.
     */
    status = pjsip_endpt_create_request_fwd(global.endpt, rdata, NULL,
					    NULL, 0, &tdata);
    if (status != PJ_SUCCESS) {
		pjsip_endpt_respond_stateless(global.endpt, rdata,
						  PJSIP_SC_INTERNAL_SERVER_ERROR, NULL,
						  NULL, NULL);
		return PJ_TRUE;
    }


    /* Process routing */
    status = proxy_process_routing(tdata);
    if (status != PJ_SUCCESS) {
		app_perror("Error processing route", status);
		return PJ_TRUE;
    }

    /* Calculate target */
    status = proxy_calculate_target(rdata, tdata);
    if (status != PJ_SUCCESS) {
		app_perror("Error calculating target", status);
		return PJ_TRUE;
    }

    if(rdata->msg_info.msg->line.req.method.id == PJSIP_REGISTER_METHOD){
    	pjsip_endpt_respond_stateless(global.endpt, rdata,
    								PJSIP_SC_OK, NULL, NULL, NULL);
    	return PJ_TRUE;
    }

//    else if(rdata->msg_info.msg->line.req.method.id == PJSIP_INVITE_METHOD){
//    	pjsip_endpt_respond_stateless(global.endpt, rdata,
//    			PJSIP_SC_RINGING, NULL, NULL, NULL);
//    	return PJ_TRUE;
//    }

    /* Target is set, forward the request */
    status = pjsip_endpt_send_request_stateless(global.endpt, tdata, 
						NULL, NULL);
    if (status != PJ_SUCCESS) {
		app_perror("Error forwarding request", status);
		return PJ_TRUE;
    }

    return PJ_TRUE;
}


/* Callback to be called to handle incoming response. */
static pj_bool_t on_rx_response( pjsip_rx_data *rdata )
{
    pjsip_tx_data *tdata;
    pjsip_response_addr res_addr;
    pjsip_via_hdr *hvia;
    pj_status_t status;

    /* Create response to be forwarded upstream (Via will be stripped here) */
    status = pjsip_endpt_create_response_fwd(global.endpt, rdata, 0, &tdata);
    if (status != PJ_SUCCESS) {
		app_perror("Error creating response", status);
		return PJ_TRUE;
    }

    /* Get topmost Via header */
    hvia = (pjsip_via_hdr*) pjsip_msg_find_hdr(tdata->msg, PJSIP_H_VIA, NULL);
    if (hvia == NULL) {
		/* Invalid response! Just drop it */
		pjsip_tx_data_dec_ref(tdata);
		return PJ_TRUE;
    }

    /* Calculate the address to forward the response */
    pj_bzero(&res_addr, sizeof(res_addr));
    res_addr.dst_host.type = PJSIP_TRANSPORT_UDP;
    res_addr.dst_host.flag = pjsip_transport_get_flag_from_type(PJSIP_TRANSPORT_UDP);

    /* Destination address is Via's received param */
    res_addr.dst_host.addr.host = hvia->recvd_param;
    if (res_addr.dst_host.addr.host.slen == 0) {
		/* Someone has messed up our Via header! */
		res_addr.dst_host.addr.host = hvia->sent_by.host;
    }

    /* Destination port is the rpot */
    if (hvia->rport_param != 0 && hvia->rport_param != -1)
    	res_addr.dst_host.addr.port = hvia->rport_param;

    if (res_addr.dst_host.addr.port == 0) {
		/* Ugh, original sender didn't put rport!
		 * At best, can only send the response to the port in Via.
		 */
		res_addr.dst_host.addr.port = hvia->sent_by.port;
    }

    /* Forward response */
    status = pjsip_endpt_send_response(global.endpt, &res_addr, tdata, 
				       NULL, NULL);
    if (status != PJ_SUCCESS) {
		app_perror("Error forwarding response", status);
		return PJ_TRUE;
    }

    return PJ_TRUE;
}

int stateless_proxy_init_all(void)
{
    pj_status_t status;

    global.port = 5060;
    pj_log_set_level(5);


    status = init_stack();
    if (status != PJ_SUCCESS) {
		app_perror("Error initializing stack", status);
		return 1;
    }

    status = init_proxy();
    if (status != PJ_SUCCESS) {
	app_perror("Error initializing proxy", status);
	return 1;
    }

    status = init_stateless_proxy();
    if (status != PJ_SUCCESS) {
	app_perror("Error initializing stateless proxy", status);
	return 1;
    }

    return 0;
}

int stateless_proxy_destory_all(void)
{
	destroy_stack();
	return 0;
}

int stateless_proxy_work_thread_callback(void *p)
{
	PJ_UNUSED_ARG(p);

	pj_time_val delay = {0, 10};
    while (!global.quit_flag) {
    	pjsip_endpt_handle_events(global.endpt, &delay);
    }

    return 0;
}
