#ifndef LAYER
#define LAYER

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Layer {
	unsigned int w, h;
	int offsetX, offsetY; // signed for camera movement
	char *contents;
} Layer;

Layer *new_layer(const int w, const int h, const int offsetX, const int offsetY, char *contents);
void layer_shift(Layer *layer, const int x, const int y);
void layer_setpos(Layer *layer, const int x, const int y);
int layer_getlen(const Layer *l);
char* layer_getDiff(Layer *a, Layer *b); 

#endif
