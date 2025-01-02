#include "layer.h"

Layer *new_layer(int w, int h, int offsetX, int offsetY, char *contents) {
	Layer *l = (Layer*)malloc(sizeof(Layer));
	*l = (Layer) {
 		.w = w,
		.h = h,
		.offsetX = offsetX,
		.offsetY = offsetY,
		.contents = malloc(w*h),
	};
	l->contents = contents;
	return l;
}

int layer_getlen(Layer *l) {
	return (l->w * l->h);
}