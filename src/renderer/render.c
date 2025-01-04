// #include <string.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#include "render.h"
#include "../utils/util.h"
#include "../input/manager.h"

// bool rendering = false;
int x = 0;
void render(LayerManager *lm)
{
	CURSOR_TO(0, 21);
	printf(" %d\n", x++);
	// render only when at least one layer is updated or modified.
	if (lm->layersUpdated == true)
	{
		unsigned int l = 0;
		while (l < lm->count)
		{
			Layer *layer = *(lm->layers + l);
			int offset = layermgr_getlayeroffset(lm, l++),
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
		printf("%s", lm->buffer);
		lm->layersUpdated = false;
	}
}

// typedef struct
// {
// 	pthread_t *thread;
// 	LayerManager *lm;
// } _RenderArgToken;

// asynchronously running function, executing Synchronous function/instructions.
// void *_async_renderer_runner(void *args)
// {
// 	_RenderArgToken *t = (_RenderArgToken *)args;

// 	pthread_join(t->thread, NULL);
// 	while (rendering)
// 	{
// 		render(t->lm);
// 		usleep(10000);
// 	}
// 	// pthread_testcancel();
// 	return NULL;
// }

// pthread_t *renderer_start(LayerManager *lm)
// {
// 	rendering = true;
// 	pthread_t *thread = malloc(sizeof(pthread_t));

// 	_RenderArgToken t;
//     t.lm = lm;
// 	t.thread = thread;

// 	pthread_create(thread, NULL, _async_renderer_runner, (void*)&t);
// 	pthread_join(*thread, NULL);
// 	return thread;
// }

// void render_stop(pthread_t thread)
// {
// 	pthread_cancel(thread);
// }
