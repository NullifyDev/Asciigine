#include <string.h>

#include "render.h"
#include "../utils/util.h"
#include "../utils/fastprint.h"

#include <stdio.h>

void render(LayerManager *lm)
{
	unsigned int l = 0;
	while (l < lm->count)
	{
		Layer *layer = *(lm->layers + l++);
		int offset = layermgt_layerOffset(lm, layer),
			len = layer_getlen(layer), 
			i = -1, j = -1;

		while (++i < len)
		{
			if (i > layer->w - 1 && i % layer->w == 0)
				lm->buffer[++j + offset] = '\n';
			
			lm->buffer[++j + offset] = layer->contents[i];
		}
	}
	printf(lm->buffer);
}