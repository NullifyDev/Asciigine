#include <stdio.h>
#include <stdlib.h>

#include "log.h"

char *file_read(const char *path) {
  FILE *file = fopen(path, "r");
  if (!file) {
    perror("file_read: ");
    return NULL;
  }

  fseek(file, 0, SEEK_END);
  long size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *content = malloc(size + 1);
  if (!content) {
    fclose(file);
    return NULL;
  }

  size_t bytesRead = fread(content, 1, size, file);
  content[bytesRead] = '\0';

  fclose(file);
  return content;
}
