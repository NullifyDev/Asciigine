#include "layer.h"

Layer *new_layer(const int w, const int h, const int offsetX, const int offsetY, char *contents) {
	Layer *l = malloc(sizeof(Layer));
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