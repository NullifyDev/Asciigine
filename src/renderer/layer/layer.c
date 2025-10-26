#include "layer.h"

Layer *new_layer(int w, int h, int offsetX, int offsetY, char *contents) {
	Layer *l = calloc(1, sizeof(Layer));
	l->w = w;
	l->h = h;
	l->offsetX = offsetX;
	l->offsetY = offsetY;
	l->contents = contents;
	return l;
}

void layer_setpos(Layer *layer, const int x, const int y) {
	layer->offsetX = x;
	layer->offsetY = y;
}

void layer_shift(Layer *layer, const int x, const int y) {
	layer_setpos(layer, layer->offsetX + x, layer->offsetY + y);
}

int layer_getlen(const Layer *l) {
	return ((l->w) * l->h) * 2;
}

char* layer_getDiff(Layer *a, Layer *b) 
{
	char *aa = a->contents,
		 *ab = b->contents;
	
	int tsa =  a->h * a->w + a->h, // total size of a
		tsb =  b->h * b->w + b->h,  // total size of b
		ts  = (tsa > tsb) * tsa + (tsa <=tsb) *tsb;

	char *diff = (char *)malloc(ts),
		 *dptr = diff,
		 *res  = NULL;
		 
	int shorter = (tsa <= tsb) * tsa + (tsa > tsb) * tsb,
		s = shorter;

	while(s-- >= 0) 
		if(*(aa++) != *ab) *(dptr++) = *(ab++);
		else ab++;

	if (shorter == tsa) {
		s = tsb - tsa;
		while(s-- >= 0)
			*(dptr++) = *(ab++);
	} else {
		s = tsa - tsb;
		while (s-- >= 0)
			*(dptr++) = *(aa++);
	}

	res = (char *)memcpy(
		malloc(dptr - diff), 
		diff, 
		dptr - diff
	);
	free(diff);
	return res;
}
