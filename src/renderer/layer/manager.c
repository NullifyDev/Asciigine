#include "../../utils/log.h"
#include "../../utils/util.h"

#include "manager.h"

#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>

LayerManager *layermgr_init(int capacity, int w, int h)
{
	LayerManager *lm = calloc(sizeof(LayerManager), 1);
	lm->w = w * 2; // multiply by 2 because text height-to-width ratio is 2:1
	lm->h = h;
	lm->buffer = calloc(sizeof(unsigned char), (lm->w * lm->h) * 2 + lm->h);
	lm->capacity = capacity;
	lm->layers = calloc(sizeof(Layer*), lm->capacity);
	lm->count = 0;
	lm->updated = false;

	lm->Empty = calloc(sizeof(Layer), 1);
	return lm;
}

void layermgr_add(LayerManager *lm, const unsigned int layer, Layer *l)
{
	if (l->contents == NULL) error("Layer contents are null - Aborting layer addition");

	Layer *lay = lm->layers[layer];
	if (lay != NULL)
	{
		error("Specified layer is already taken - did you mean to modify or set to a different layer?\n");
		exit(0);
		return;
	}
	if (lm->layers + layer >= lm->layers + lm->capacity || lm->layers + layer < lm->layers)
	{
		error("A specified layer position is out of bounds. Check your target layer and layer manager size\n");
		exit(1);
		return;
	}
	lm->layers[layer] = l;
	lm->count++;
	lm->updated = true;
}
int layermgr_size(LayerManager *lm)
{
	return (lm->w * lm->h) * 2;
}

int layermgr_getlayeroffset(LayerManager *lm, const unsigned int layer)
{
	Layer *l = lm->layers[layer];
	return ((lm->w * l->offsetY) + (l->offsetY * 2) + (l->offsetX * 2));
}
// void layermgr_setlayeroffset(LayerManager *lm, int layer, int x, int y)
void layermgr_setlayeroffset(LayerManager *lm, const unsigned int l, const int x, const int y)
{
	layer_setpos(lm->layers[l], x, y);
	lm->updated = true;
}

void layermgr_shiftlayer(LayerManager *lm, const unsigned int l, const int x, const  int y)
{
	layermgr_setlayeroffset(lm, l, lm->layers[l]->offsetX + x, lm->layers[l]->offsetY + y);
}

// void layermgr_debug_printlayers(LayerManager *lm) {
// 	Layer *ptr = lm->layers;
// 	printf("lm->layers: %p | lm->capacity): %d [ \n", p, lm->capacity);
// 	while (ptr <= (sizeof(Layer *) * lm->capacity) + lm->layers) {
// 		printf(" ", lm->);
// 	}
// 	printf("]");
// }