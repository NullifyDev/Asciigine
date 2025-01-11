#include "manager.h"
#include "log.h"
#include "util.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// TODO: lacking some error handling
LayerManager *layermgr_init(int capacity, int w, int h) {
  LayerManager *lm = malloc(sizeof *lm);
  lm->w = w * 2;  // multiply by 2 because text height-to-width ratio is 2:1
  lm->h = h;
  lm->buffer = malloc(lm->w * lm->h);
  lm->capacity = capacity;

  // calloc required! otherwise if (lm->layers[layer] != NULL) is UB
  lm->layers = calloc(sizeof *lm->layers * lm->capacity, sizeof *lm->layers);
  lm->count = 0;
  lm->layersUpdated = false;
  return lm;
}

void layermgr_add(LayerManager *lm, const unsigned int layer, Layer *l) {
  if (l->contents == NULL) { error("Layer contents are null - Aborting layer addition"); }
  if (lm->layers[layer] != NULL) {
    error("Specified layer is already taken - did you mean to modify or set to a different layer?\n");
    exit(1);
    return;
  }
  if (lm->layers + layer >= lm->layers + lm->capacity || lm->layers + layer < lm->layers) {
    error("A specified layer position is out of bounds. Check your target layer and layer manager size\n");
    exit(1);
    return;
  }
  lm->layersUpdated = true;
  lm->layers[layer] = l;
  lm->count++;
}
int layermgr_size(LayerManager *lm) {
  return lm->w * lm->h;
}
int layermgr_getlayeroffset(LayerManager *lm, int layer) {
  CURSOR_TO(0, 25);
  Layer *l = lm->layers[layer];
  return ((lm->w * l->offsetY) + l->offsetY + (l->offsetX));
}
void layermgr_setlayeroffset(LayerManager *lm, int layer, int x, int y) {
  Layer *l = lm->layers[layer];
  l->offsetX = x;
  l->offsetY = y;
}
void layermgr_shiftlayer(LayerManager *lm, int layer, int x, int y) {
  Layer *l = lm->layers[layer];
  l->offsetX += x;
  l->offsetY += y;
  lm->layersUpdated = true;
}
