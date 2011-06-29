/*
 * main.c
 *
 *  Created on: 2011-6-28
 *      Author: Yewberry
 */
#define THIS_FILE   "main.c"

#include "stateless_proxy.h"
#include "common.h"

struct global_struct global;

int main(int argc, char *argv[])
{
	stateless_proxy_init_all();
	pj_status_t status = pj_thread_create(global.pool, "sproxy", &stateless_proxy_work_thread_callback,
			      NULL, 0, 0, &global.thread);
    if (status != PJ_SUCCESS) {
		app_perror("Error creating thread", status);
		return 1;
    }

    pj_thread_join(global.thread);
    stateless_proxy_destory_all();

	return 0;
}

