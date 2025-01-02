#ifndef LAYERMANAGER
#define LAYERMANAGER

#include "layer.h"

typedef struct LayerManager
{
	Layer **layers;
	unsigned int w, h, capacity, count;
	char *buffer;
} LayerManager;

LayerManager *layermgr_init(int capacity, int w, int h);
void layermgr_add(LayerManager *this, const unsigned int layer, Layer *l);
// void layermgr_modify(unsigned int layer, char *content);
// void layermgr_rem(unsigned int layer);
int layermgt_size(LayerManager *lm);
int layermgt_layerOffset(LayerManager *lm, Layer *l);

#endif