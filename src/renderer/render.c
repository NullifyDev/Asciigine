// #include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#include "render.h"
#include "../utils/util.h"
#include "../input/manager.h"
#include "../utils/log.h"

int x = 0;
void render(LayerManager *lm)
{
	if (lm == NULL) return;
	if (!lm->updated) return;
	
	CLEAR();

	int l = -1;
	while (++l < lm->count)
	{
		Layer *layer = lm->layers[l];
		if (layer == NULL) error("[INTERNAL ERROR]: a layer is either null or not fully initialized.");
		
		unsigned int offset = layermgr_getlayeroffset(lm, l),
			len = layer_getlen(layer),
			i = 0, j = 0;

		while (j < len)
		{
			lm->buffer[j++ + offset] = ' ';
			lm->buffer[j++ + offset] = layer->contents[i++];
		}
	}
	CURSOR_TO(0, 0);
	printf("%s\n", lm->buffer);
	lm->updated = false;
}