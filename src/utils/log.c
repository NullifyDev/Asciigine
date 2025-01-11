#include "log.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

int maxLogLevel;
void logger(int level, const char *msg) {
  if (level > maxLogLevel) return;
  switch (level) {
    case LOG_LEVEL_PRINT:
      printf("%s", msg);
      return;
    case LOG_LEVEL_ERROR:
      printf("\033[38;2;255;0;0m[ERROR]:   %s\033[0m\n", msg);
      return;
    case LOG_LEVEL_WARNING:
      printf("\033[38;2;255;255;0m[WARNING]: %s\033[0m\n", msg);
      return;
    case LOG_LEVEL_DEBUG:
      printf("\033[38;2;0;255;255m[DEBUG]:   %s\033[0m\n", msg);
      return;
    case LOG_LEVEL_LOG:
      printf("[LOG]:     %s\033[0m\n", msg);
      return;
    case LOG_LEVEL_VERBOSE:
      printf("[VERBOSE]: %s\033[0m\n", msg);
      return;
    default:
      printf("[LOG LEVEL %d]: %s\n", level, msg);
      return;
  }
}

void print(const char *msg) {
  logger(0, msg);
}

void error(const char *msg) {
  logger(LOG_LEVEL_ERROR, msg);
}

void warning(const char *msg) {
  logger(LOG_LEVEL_WARNING, msg);
}

void debug(const char *msg) {
  logger(LOG_LEVEL_DEBUG, msg);
}

void logger_log(const char *msg) {
  logger(LOG_LEVEL_LOG, msg);
}

void verbose(const char *msg) {
  logger(LOG_LEVEL_VERBOSE, msg);
}
