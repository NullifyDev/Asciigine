#include "heart.h"
#include "utils/args.h"
#include "utils/util.h"
#include "input/manager.h"
#include "renderer/layer/manager.h"

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	// HIDE_CURSOR();
	// SHOW_CURSOR();

	// clear();

	maxLogLevel = 2;

	LayerManager *lm = layermgr_init(3, 40, 20);
	InputManager *im = input_init(60, 5);
	
	char *map = file_read("/home/saturn/Asciigine/src/maps/test", 800);

	layers_add(lm, 3, (Layer *[]) 
	{
		new_layer(40, 20,  0,  0, map),
		new_layer( 1,  1, 36,  3, "X"),
		new_layer( 1,  1,  5,  5, "@"),
	});

	keys_add(im, 5, (Key[])
	{
		{'w', moveup, (void*[]){ (int *)2, lm, im }},
		{'s', movedown, (void*[]){ (int *)2, lm, im }},
		{'a', moveleft, (void*[]){ (int *)2, lm, im }},
		{'d', moveright, (void*[]){ (int *)2, lm, im }},
		{'q', engine_exit, (void*[]){ (int *)2, lm, im } }
	});


	// _render(lm);

	start(lm, im);

	while (lm->thread != 0 && lm->thread != 0) ;

	// pthread_join(render_pt, NULL);
	// pthread_join(input_pt, NULL);

	return 0;
}