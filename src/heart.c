#include "heart.h"
#include "input/manager.h"
#include "renderer/layer/manager.h"
#include <pthread.h>


void *moveup(void **args)
{
	int *alen = args[0];
	if (*alen != 2) printf("moveup has incorrect arg lenfth\n");

	layermgr_shiftlayer((LayerManager *)args, 2, 0, -1);
	return NULL;
}
void *movedown(void **args)
{
	int *alen = args[0];
	if (*alen != 2) printf("movedown has incorrect arg lenfth\n");

	layermgr_shiftlayer((LayerManager *)args, 2, 0, 1);
	return NULL;
}
void *moveleft(void **args)
{
	int *alen = args[0];
	if (*alen != 2) printf("moveleft has incorrect arg lenfth\n");

	layermgr_shiftlayer((LayerManager *)args, 2, -1, 0);
	return NULL;
}
void *moveright(void **args)
{
	int *alen = args[0];
	if (*alen != 2) printf("moveright has incorrect arg lenfth\n");

	layermgr_shiftlayer((LayerManager *)args, 2, 1, 0);
	return NULL;
}

void free_engine(void)
{
	layermgr_free(lm);
	SHOW_CURSOR();
	// free(et->lm->)
}

void *engine_exit(void *args[])
{
	LayerManager *lm = args[1];
	InputManager *im = args[2];

	// _running = false;
	pthread_join(*lm->thread, lm->thread_ret);
	pthread_join(*im->thread, im->thread_ret);
	free_engine();
	return NULL;
}

int start(LayerManager *lm, InputManager *im)
{	
	// int status = 0;
	pthread_create(lm->thread, NULL, render, lm);
	// if (status != 0) return status; 

	pthread_create(im->thread, NULL, _input_read, im);
	// if (status != 0) return status; 

	return 0;
}