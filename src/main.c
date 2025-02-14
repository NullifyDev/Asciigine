#include "init.c"

int main()
{
	HIDE_CURSOR();
	SHOW_CURSOR();
		
	CLEAR();


	maxLogLevel = 2;

	// LayerManager *lm = layermgr_init(3, 40, 20);

	init();

	// while(1) {}

	return 0;
}