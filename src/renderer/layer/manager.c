#include "../../utils/log.h"
#include "layer.h"

#include "manager.h"



LayerManager *layermgr_init(int capacity, int w, int h)
{
	LayerManager *lm = calloc(1, sizeof(LayerManager));
	lm->w = w * 2; // multiply by 2 because text height-to-width ratio is 2:1
	lm->h = h;
	lm->buffer = (char *)calloc((lm->w * lm->h) * 2 + lm->h, sizeof(unsigned char));
	lm->capacity = capacity;
	lm->layers = calloc(lm->capacity, sizeof(Layer*));
	lm->count = 0;
	lm->updated = true;
	lm->thread_ret = NULL;
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
	if (lm->layers + layer >= lm->layers + lm->capacity) // || lm->layers + layer < lm->layers)
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

void layermgr_shiftlayer_ca(Args *coreargs, const unsigned int l, const int x, const  int y)
{
	LayerManager *lm = (LayerManager *)coreargs->ptrs[0]; 
	layermgr_setlayeroffset(lm, l, lm->layers[l]->offsetX + x, lm->layers[l]->offsetY + y);
}


void layermgr_free(LayerManager *lm) {
	if (lm == NULL) return;
	lm->buffer = NULL;
	free(lm->buffer);
	lm->layers = NULL;
	free(lm->buffer);

	lm->w = 0;
	lm->h = 0;
	lm->capacity = 0;
	lm->count = 0;
	lm->updated = 0;
	lm->thread_ret = NULL;

	free(lm);
}

void layers_add(LayerManager *lm, unsigned int count, Layer *layers[]) 
{
	unsigned int newcap = (count + lm->count) < lm->capacity ? count : lm->capacity + count,
				 newcount = 0;

    Layer **temp = calloc(newcap, sizeof(Layer *));

    if (!temp) return;

	int i = 0;
	while (i < lm->count+count) 
	{
		temp[i] = i < lm->count ? lm->layers[i] : layers[i];
		i++; newcount++;
	}

	free(lm->layers);
    lm->layers = temp;
	lm->count = newcount;
	lm->capacity = newcap;
}

// void layermgr_debug_printlayers(LayerManager *lm) {
// 	Layer *ptr = lm->layers;
// 	printf("lm->layers: %p | lm->capacity): %d [ \n", p, lm->capacity);
// 	while (ptr <= (sizeof(Layer *) * lm->capacity) + lm->layers) {
// 		printf(" ", lm->);
// 	}
// 	printf("]");
// }