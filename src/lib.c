#include "minilib.h"

int mx_strlen(const char *s)
{
    int len = 0;

    while (*s++)
        len += 1;

    return len;
}