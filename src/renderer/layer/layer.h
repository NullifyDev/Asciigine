#ifndef LAYER
#define LAYER

#include <stdlib.h>
#include <stdbool.h>

typedef struct Layer {
	unsigned int w, h;
	int offsetX, offsetY;
	char *contents;
} Layer;

Layer *new_layer(const int w, const int h, const int offsetX, const int offsetY, char *contents);
void layer_shift(Layer *layer, const int x, const int y);
void layer_setpos(Layer *layer, const int x, const int y);
int layer_getlen(const Layer *l);

#endif