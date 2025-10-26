#include "heart.h"
#include "input/manager.h"
#include "renderer/layer/manager.h"
#include "renderer/render.h"
#include "utils/args.h"
#include <pthread.h>



void *moveup(void **args)
{
	LayerManager *lm = (LayerManager*)args;
	layermgr_shiftlayer(lm, 2, 0, -1);
	return NULL;
}

void *movedown(void **args)
{
	LayerManager *lm = (LayerManager*)args;
	layermgr_shiftlayer(lm, 2, 0, -1);
	return NULL;
}

void *moveleft(void **args)
{
	LayerManager *lm = (LayerManager*)args;
	layermgr_shiftlayer(lm, 2, 0, -1);
	return NULL;
}

void *moveright(void **args)
{
	LayerManager *lm = (LayerManager*)args;
	layermgr_shiftlayer(lm, 2, 0, -1);
	return NULL;
}

void free_engine(void)
{
	layermgr_free(lm);
	SHOW_CURSOR();
	// free(et->lm->)
}

void *engine_exit(void **args)
{
	// Heart *heart = (Heart *)&args;
	// _running = false;
	// pthread_join(*heart->lm->thread, heart->lm->thread_ret);
	// pthread_join(*heart->im->thread, heart->im->thread_ret);
	free_engine();
	return NULL;
}

int start(Heart *heart)
{
	while (true) 
	{
		_render(heart->lm);
		input_read(heart->im);
	}

    // pthread_mutex_t init_mutex = PTHREAD_MUTEX_INITIALIZER;
    // pthread_mutex_lock(&init_mutex);

    // heart->lm->thread = calloc(1, sizeof(pthread_t));
    // heart->im->thread = calloc(1, sizeof(pthread_t));


    // int ret1 = pthread_create(heart->lm->thread, NULL, render, heart->lm);
    // int ret2 = pthread_create(heart->im->thread, NULL, _input_read, heart->im);
    
    // pthread_mutex_unlock(&init_mutex);
    // return (ret1 == 0 && ret2 == 0) ? 0 : -1;
}