#include <stdio.h>
#include <time.h>

#include "utils/log.h"
#include "renderer/layerManager.h"
#include "renderer/render.h"
#include "utils/util.h"

int main()
{
	currLogLevel = 2;
	LayerManager *lm = layermgr_init(3, 40, 20);

	layermgr_add(lm, 0, new_layer(40, 20, 0, 0, "#########################################                                      ##                                      ##                                      ##                                      ##                                      ##                                      ##                                      ##                                      ##                                      ##                                      ##                                      ##                                      ##                                      ##                                      ##                                      ##                                      ##                                      #########################################"));
	layermgr_add(lm, 1, new_layer(1, 1, 1, 1, "@"));

	int i = -1;
	int cycles = 1000000;
	long res = 0;
	clock_t start = clock();
	while(++i < cycles) {
		CURSOR_TO(1, 2);
		clock_t s = clock();
		render(lm);
		res += (clock_t)clock() - s;
	}
	fp_print("Average Runtime in %d cyckes: %ldμs\n", cycles, (long)(res/cycles));

	return 0;
}