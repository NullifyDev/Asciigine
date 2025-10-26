#ifndef LAYERMANAGER
#define LAYERMANAGER

#include <stdbool.h>
#include <pthread.h>

#include "layer.h"
#include "../../utils/util.h"
#include "../../utils/args.h"

#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct LayerManager
{
	Layer **layers;
	unsigned int w, h, capacity, count;
	char *buffer;
	bool updated;
	const Layer *Empty;
	pthread_t *thread;
	void ** thread_ret;
} LayerManager;

static LayerManager *lm;

LayerManager *layermgr_init(int capacity, int w, int h);
void layermgr_add(LayerManager *lm, const unsigned int layer, Layer *l);
// void layermgr_modify(unsigned int layer, char *content);
// void layermgr_rem(unsigned int layer);
int layermgr_size(LayerManager *lm);
int layermgr_getlayeroffset(LayerManager *lm, const unsigned int layer);
void layermgr_setlayeroffset(LayerManager *lm, const unsigned int l, const int x, const int y);
void layermgr_shiftlayer(LayerManager *lm, const unsigned int l, const int x, const  int y);
void layermgr_shiftlayer_ca(Args *coreargs, const unsigned int l, const int x, const  int y);

void layermgr_debug_printlayers(LayerManager *lm);
void layermgr_free(LayerManager *lm);

void layers_add(LayerManager *lm, unsigned int count, Layer *layers[]);

#endif