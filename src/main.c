#include "init.h"
#include "utils/log.h"

int main(void) {
  HIDE_CURSOR();
  SHOW_CURSOR();

  maxLogLevel = 2;

  init();

  while (1) {}

  return 0;
}
