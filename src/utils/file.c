#include "file.h"

char* file_read(char* path, int size)
{
    if (path == NULL) {
        printf("NULL path passed\n");
        return NULL;
    }

    FILE *f;
    f = fopen(path, "r");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    fseek(f, 0, SEEK_SET);

    char* content = calloc(size + 1, sizeof(char));
    if (!content) {
        fclose(f);
        return NULL;
    }

    size_t bytesRead = fread(content, 1, size, f);
    content[bytesRead] = '\0';

    fclose(f);
    return content;
}