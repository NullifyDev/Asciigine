#include "heart.h"
#include "utils/args.h"
#include "input/manager.h"
#include "renderer/layer/manager.h"

int main(void)
{
	// HIDE_CURSOR();
	// SHOW_CURSOR();

	// clear();

	maxLogLevel = 2;
	Heart *heart = calloc(1, sizeof(Heart));
	heart->lm = layermgr_init(3, 40, 20);
	heart->im = input_init(60, 5);

	char *map = file_read("/home/saturn/Asciigine/src/maps/test", 800);

	layers_add(heart->lm, 3, (Layer *[])
	{
		new_layer(40, 20,  0,  0, map),
		new_layer( 1,  1,  36, 3, "X"),
		new_layer( 1,  1,  5,  5, "@"),
	});

	// Args *coreargs = args_create(2, (void*[]){heart->lm, heart->im});

	// key_new('w', );
	keys_add(heart->im, 5, (Key*)
	{
		key_new('w', moveup, 	(void**)&heart),
		key_new('s', movedown, 	(void**)&heart),
		key_new('a', moveleft,	(void**)&heart),
		key_new('d', moveright,  (void**)&heart),
		key_new('q', engine_exit,(void**)&heart)
	});

	// _render(heart->lm);

	start(heart);

	// while (heart->lm->thread != 0 && heart->lm->thread != 0);

	// pthread_join(render_pt, NULL);
	// pthread_join(input_pt, NULL);

	return 0;
}