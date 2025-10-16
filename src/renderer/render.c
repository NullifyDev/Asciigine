#include "render.h"

int x = 0;
void _render(LayerManager *lm)
{
	// printf("_render(LayerManager *): hit!\n");
	if (!lm->updated) return;
	
	clear();

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
	printf("%s\n%d", lm->buffer, x);
	lm->updated = false;
}

void *render(void *arg) {
	// printf("render: running!\n");
	LayerManager * lm = (LayerManager *)arg;

	while(lm->thread != 0) 
	{
		_render(lm);
	}

	return NULL;
}

// void *render_start(void *layermgr)
// {
// 	printf("render: initializing...  ");
// 	lm = (LayerManager *)layermgr;
// 	_render_alive_a = true;
// 	printf("%s\n", lm == NULL ? "Failed (NULL)" : "Done!");
// 	if (pthread_create((pthread_t *)render_pt, NULL, _render, NULL) != 0) {
//         perror("Failed to create renderer thread \"renderer_pt\"");
//         exit(EXIT_FAILURE);
//     }
// 	return NULL;
// }