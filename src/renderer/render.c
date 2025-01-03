#include <string.h>

#include "render.h"
#include "../utils/util.h"

#include <stdio.h>
#include <pthread.h>

int running = 0;
void render(LayerManager *lm)
{
	// render only when at least one layer is updated or modified.
	if (lm->layersUpdated == false) return;

	unsigned int l = 0;
	while (l < lm->count)
	{
		Layer *layer = *(lm->layers + l++);
		int offset = layermgr_getlayeroffset(lm, layer),
			len = layer_getlen(layer),
			i = -1, j = -1;

		while (++i < len)
		{
			if (i > (int)layer->w - 1 && i % layer->w == 0)
				lm->buffer[++j + offset] = '\n';

			lm->buffer[++j + offset] = layer->contents[i];
			lm->buffer[++j + offset] = ' ';
		}
	}
	CURSOR_TO(0, 2);
	printf(lm->buffer);
}


void *_async_runner(void *arg)
{
	LayerManager *lm = (LayerManager *)arg;
	while (running)
	{
		render(lm);
	}
	pthread_testcancel();
	return NULL;
}

void renderer_start(LayerManager *lm)
{
	running = 1;
	pthread_t thread;
	int ret = pthread_create(&thread, NULL, _async_runner, lm);
	if (ret)
	{
		perror("pthread_create");
		return;
	}
	pthread_join(thread, NULL);
}