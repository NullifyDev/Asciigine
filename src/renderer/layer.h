#ifndef LAYER
#define LAYER

#include <stdlib.h>

typedef struct Layer {
	unsigned int w, h;
	int offsetX, offsetY;
	char *contents;
} Layer;

Layer *new_layer(int w, int h, int offsetX, int offsetY, char *contents);
int layer_getlen(Layer *l);

#endif