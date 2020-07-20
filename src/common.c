#include "common.h"

void Error(char *s)
{
    fprintf(stderr, "%s\n", s);
    exit(1);
}