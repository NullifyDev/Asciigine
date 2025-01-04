#include "layer.h"

Layer *new_layer(int w, int h, int offsetX, int offsetY, char *contents) {
	Layer *l = (Layer*)malloc(sizeof(Layer));
	l->w = w;
	l->h = h;
	l->offsetX = offsetX;
	l->offsetY = offsetY;
	l->contents = contents;
	return l;
}

void layer_shift(Layer *layer, int x, int y) {
	layer->offsetX += x;
	layer->offsetY += y;
}

int layer_getlen(Layer *l) {
	return ((l->w) * l->h);
}