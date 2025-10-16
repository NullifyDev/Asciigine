#include "log.h"

void logger(LogLevel level, const char *msg)
{
	if (level > maxLogLevel) return;
	switch (level)
	{
	case LOGLEVEL_PRINT:
		printf("%s", msg);
		return;
	case LOGLEVEL_ERROR:
		printf("\033[38;2;255;0;0m[ERROR]:   %s\033[0m\n", msg);
		return;
	case LOGLEVEL_WARNING:
		printf("\033[38;2;255;255;0m[WARNING]: %s\033[0m\n", msg);
		return;
	case LOGLEVEL_DEBUG:
		printf("\033[38;2;0;255;255m[DEBUG]:   %s\033[0m\n", msg);
		return;
	case LOGLEVEL_LOG:
		printf("[LOG]:     %s\033[0m\n", msg);
		return;
	case LOGLEVEL_VERBOSE:
		printf("[VERBOSE]: %s\033[0m\n", msg);
		return;
	default:
		printf("[LOG LEVEL %d]: %s\n", level, msg);
		return;
	}
}

void print(const char *msg)
{
	logger(0, msg);
}

void error(const char *msg)
{
	logger(LOGLEVEL_ERROR, msg);
}

void warning(const char *msg)
{
	logger(LOGLEVEL_WARNING, msg);
}

void debug(const char *msg)
{
	logger(LOGLEVEL_DEBUG, msg);
}

void _log(const char *msg)
{
	logger(LOGLEVEL_LOG, msg);
}

void verbose(const char *msg)
{
	logger(LOGLEVEL_VERBOSE, msg);
}