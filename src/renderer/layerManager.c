#include "../utils/log.h"

#include "layerManager.h"

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

LayerManager *layermgr_init(int capacity, int w, int h)
{
	w *= 2;
	LayerManager *lm = malloc(sizeof(LayerManager) * 1);
	*lm = (LayerManager){
		.w = w,
		.h = h,
		.buffer = malloc(sizeof(unsigned char) * ((w * 2) * h)),
		.layers = malloc(sizeof(Layer) * capacity),
		.capacity = capacity,
		.count = 0,
		.layersUpdated = true,
	};
	return lm;
}

void layermgr_add(LayerManager *this, const unsigned int layer, Layer *l)
{
	if (l->contents == NULL)
	{
		error("Layer contents are null - Aborting layer addition");
	}
	if (*(this->layers + layer) != NULL)
	{
		error("Specified layer (%d) is already taken - did you mean to modify or set to a different layer?\n");
		exit(1);
		return;
	}
	if (this->layers + layer >= this->layers + this->capacity || this->layers + layer < this->layers)
	{
		error("A specified layer position is out of bounds. Check your target layer and layer manager size\n");
		exit(1);
		return;
	}
	*(this->layers + layer) = l;
	this->count++;
}
// void layermgr_modify(unsigned int layer, char *content)
// {
// }
// void layermgr_rem(unsigned int layer)
// {
// }

int layermgr_size(LayerManager *lm)
{
	return lm->w * lm->h;
}

int layermgr_getlayeroffset(LayerManager *lm, Layer *l)
{
	return ((lm->w * l->offsetY) + l->offsetY + l->offsetX);
}