#include "../utils/log.h"

#include "layerManager.h"

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

LayerManager *layermgr_init(int capacity, int w, int h)
{
	LayerManager *lm = malloc(sizeof(LayerManager) * 1);
	*lm = (LayerManager) {
		.w = w,
		.h = h,
		.buffer = malloc(sizeof(unsigned char) * ((w * 2) * h)),
		.layers = malloc(sizeof(Layer) * capacity),
		.capacity = capacity,
		.count = 0,
	};
	return lm;
}

void layermgr_add(LayerManager *this, const unsigned int layer, Layer *l)
{
	if (*(this->layers + layer) != NULL) {
		printf("\033[38;2;255;0;0mSpecified layer (%d) is already taken - did you mean to modify or set to a different layer?\033[0m\n", layer);
		exit(1);
		return;
	}
	if (this->layers + layer >= this->layers + this->capacity || this->layers + layer < this->layers)
	{
		printf("\033[38;2;255;0;0mA specified layer position is out of bounds. Check your target layer and layer manager size\033[0m\n");
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

int layermgt_size(LayerManager *lm)
{
	return lm->w * lm->h;
}

int layermgt_layerOffset(LayerManager *lm, Layer *l) {
	return ((lm->w * l->offsetY) + l->offsetY + l->offsetX);
} 