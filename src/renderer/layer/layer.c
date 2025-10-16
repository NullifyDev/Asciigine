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

char* layer_getDiff(Layer *restrict a, Layer *restrict b) 
{
	char *aa = a->contents,
		 *ab = b->contents;
	
	int tsa =  a->h *  a->w +  a->h, // total size of a
		tsb = b->h * b->w + b->h; // total size of b

	char *diff = (char *)calloc((tsa > tsb) * tsa + (tsa <=tsb) *tsb, sizeof(char)),
		 *dptr = diff,
		 *res  = NULL;
		 
	while(*aa != '\0' && *ab != '\0')
		if(*(aa++) != *ab) *(dptr++) = *(ab++);

	if (*aa == '\0') while (*ab != '\0') *(dptr++) = *(ab++);
	else 			 while (*aa != '\0') *(dptr++) = *(aa++);

	aa = NULL;
	ab = NULL;
	
	res = (char *)memcpy(
		calloc(dptr - diff, sizeof(char)), 
		diff, 
		dptr - diff
	);
	free(diff);
	return res;
}
