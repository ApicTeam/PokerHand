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
bool mx_isalpha(int c);
bool mx_isdigit(int c);
bool mx_is_suit(char suit);
int mx_count_words(const char *str, char c);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcat(char *s1, const char *s2);
void mx_printstr(const char *s);

#endif // TEST_MINILIB_H
