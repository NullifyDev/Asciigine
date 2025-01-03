#ifndef LAYERMANAGER
#define LAYERMANAGER

#include "layer.h"
#include <stdbool.h>

typedef struct LayerManager
{
	Layer **layers;
	unsigned int w, h, capacity, count;
	char *buffer;
	bool layersUpdated;
} LayerManager;

LayerManager *layermgr_init(int capacity, int w, int h);
void layermgr_add(LayerManager *this, const unsigned int layer, Layer *l);
// void layermgr_modify(unsigned int layer, char *content);
// void layermgr_rem(unsigned int layer);
int layermgr_size(LayerManager *lm);
int layermgr_getlayeroffset(LayerManager *lm, Layer *l);

// void layermgr_

#endif