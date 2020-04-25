#ifndef TEST_MINILIB_H
#define TEST_MINILIB_H

/* Includes */
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

/* Prototypes */
int mx_strlen(const char *s);
void mx_strdel(char **str);
char *mx_strnew(const int size);
bool mx_isspace(char c);
char *mx_strtrim(const char *str);

#endif // TEST_MINILIB_H
