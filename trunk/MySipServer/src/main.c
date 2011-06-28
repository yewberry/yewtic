/*
 * main.c
 *
 *  Created on: 2011-6-28
 *      Author: Yewberry
 */
#define THIS_FILE   "main.c"

#include "stateful_proxy.h"
#include "common.h"

struct global_struct global;

int main(int argc, char *argv[])
{
	proxy_init_all();
	pj_status_t status = pj_thread_create(global.pool, "sproxy", &proxy_thread_callback,
			      NULL, 0, 0, &global.thread);
    if (status != PJ_SUCCESS) {
		app_perror("Error creating thread", status);
		return 1;
    }

    pj_thread_join(global.thread);
    proxy_destroy_all();

	return 0;
}
