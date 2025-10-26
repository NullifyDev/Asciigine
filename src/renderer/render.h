#ifndef RENDER
#define RENDER

#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <stdatomic.h>

#include "../utils/util.h"
#include "../input/manager.h"
#include "../utils/log.h"
#include "layer/manager.h"

// static pthread_t render_pt;

// static volatile _Atomic(bool) _render_alive_a = false;
// void *render_start(void *layermgr);

void *render    (void *arg);
void  _render   (LayerManager *lm);
void  render_end(void);

#endif
