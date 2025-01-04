#include "init.h"

#include <stdio.h>

#include "utils/log.h"
#include "renderer/render.h"
#include "utils/util.h"
#include "utils/file.h"
#include "input/manager.h"

void init()
{
	InputManager *im = input_init(60, 8);
	lm = layermgr_init(3, 40, 20);

	layermgr_add(lm, 0, new_layer(40, 20, 0, 0, file_read("/home/saturn/Asciigine/src/maps/test", 800)));
	layermgr_add(lm, 1, new_layer(1, 1, 5, 5, "@"));
	layermgr_add(lm, 2, new_layer(1, 1, 36, 3, "X"));

	Key *w = keylist_add(im->keylist, new_key('w', moveup));
	Key *s = keylist_add(im->keylist, new_key('s', movedown));
	Key *a = keylist_add(im->keylist, new_key('a', moveleft));
	Key *d = keylist_add(im->keylist, new_key('d', moveright));

	while(1) {
		input_read(im);
		render(lm);
	}

	// pthread_t *renderer = renderer_start(lm);
	// pthread_t *inputlistenner = input_startlistenner(im);
}
void moveup()
{
	layermgr_shiftlayer(lm, 1, 0, 1);
}
void movedown()
{
	layermgr_shiftlayer(lm, 1, 0, -1);
}
void moveleft()
{
	layermgr_shiftlayer(lm, 1, -1, 0);
}
void moveright()
{
	layermgr_shiftlayer(lm, 1, 1, 0);
}