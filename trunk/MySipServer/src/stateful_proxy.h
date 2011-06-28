#ifndef __STATEFUL_PROXY_H__
#define __STATEFUL_PROXY_H__

#include <pjsip.h>
#include <pjlib-util.h>
#include <pjlib.h>

void proxy_init_all(void);
void proxy_destroy_all(void);
int proxy_thread_callback(void* p);

#endif//__STATEFUL_PROXY_H__
