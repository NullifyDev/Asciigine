#include "init.h"

void init()
{
	im = input_init(60, 8);
	lm = layermgr_init(3, 40, 20);

	layermgr_add(lm, 0, new_layer(40, 20, 0, 0, file_read("/home/saturn/Asciigine/src/maps/test", 800)));
	layermgr_add(lm, 2, new_layer(1, 1, 5, 5, "@"));
	layermgr_add(lm, 1, new_layer(1, 1, 36, 3, "X"));

	im->keylist = keylist_setup(
		(Key[]) {
			{'w', moveup},
			{'s', movedown},
			{'a', moveleft},
			{'d', moveright},
			{'q', engine_exit}
		}, 5
	);

	_running = true;
	while (_running)
	{
		render(lm);
		input_read(im, lm);
	}
}
void moveup()
{
	layermgr_shiftlayer(lm, 2, 0, -1);
}
void movedown()
{
	layermgr_shiftlayer(lm, 2, 0, 1);
}
void moveleft()
{
	layermgr_shiftlayer(lm, 2, -1, 0);
}
void moveright()
{
	layermgr_shiftlayer(lm, 2, 1, 0);
}

void free_engine() {
	
	lm->buffer = NULL;
	free(lm->buffer);
	lm->capacity = 0;
	lm->count = 0;
	lm->h = 0;
	lm->w = 0;
	lm->layers = NULL;
	free(lm->layers);
	lm->updated = NULL;
	free(lm);
	// free(et->lm->)
}

void engine_exit() {
	_running = false;
	free_engine();
}