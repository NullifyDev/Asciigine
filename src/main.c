#include <stdio.h>
#include <time.h>

#include "utils/log.h"
#include "renderer/layerManager.h"
#include "renderer/render.h"
#include "utils/util.h"
#include "utils/file.h"

int main()
{
	HIDE_CURSOR();

	maxLogLevel = 2;
	LayerManager *lm = layermgr_init(3, 40, 20);

	layermgr_add(lm, 0, new_layer(40, 20, 0, 0, file_read("/home/saturn/Asciigine/src/maps/test", 800)));
	layermgr_add(lm, 1, new_layer(1, 1, 5,  5, "@"));
	layermgr_add(lm, 2, new_layer(1, 1, 36, 3, "X"));

	renderer_start(lm);

	SHOW_CURSOR();
	return 0;
}