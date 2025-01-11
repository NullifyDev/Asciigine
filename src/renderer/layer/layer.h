#ifndef LAYER
#define LAYER

typedef struct Layer {
  unsigned int w, h;
  int offsetX, offsetY;
  char *contents;
} Layer;

Layer *new_layer(int w, int h, int offsetX, int offsetY, char *contents);
void layer_shift(Layer *layer, int x, int y);
int layer_getlen(Layer *l);

#endif
