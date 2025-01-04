#include "init.c"

int main()
{
	HIDE_CURSOR();
	SHOW_CURSOR();

	maxLogLevel = 2;

	init();

	while(1) {}

	return 0;
}