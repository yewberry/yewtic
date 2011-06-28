#ifndef __COMMON_H__
#define __COMMON_H__

#include <pjsip.h>
#include <pjlib-util.h>
#include <pjlib.h>

/* Options */
struct global_struct
{
    pj_caching_pool	 cp;
    pjsip_endpoint	*endpt;
    int			 port;
    pj_pool_t		*pool;

    pj_thread_t		*thread;
    pj_bool_t		 quit_flag;

    pj_bool_t		 record_route;

    unsigned		 name_cnt;
    pjsip_host_port	 name[16];
};

static void app_perror(const char *msg, pj_status_t status)
{
    char errmsg[PJ_ERR_MSG_SIZE];

    pj_strerror(status, errmsg, sizeof(errmsg));
    PJ_LOG(1,(THIS_FILE, "%s: %s", msg, errmsg));
}

#endif//__COMMON_H__
