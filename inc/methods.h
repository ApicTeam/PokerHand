#ifndef TEST_METHODS_H
#define TEST_METHODS_H

/* Includes */
#include <stdbool.h>
#include <stdlib.h>

/* Structures */
typedef struct s_pokerHand
{
    char c1[3];
    char c2[3];
    char c3[3];
    char c4[3];
    char c5[3];
}              t_pokerHand;

/* Prototypes */
void print_error(int error_id, char *value);
t_pokerHand *get_poker_hand(const char *poker_hand);
char *mx_strcpy(char*dst, const char*src);
char *mx_del_extra_whitespaces(const char *str);

#endif//TEST_METHODS_H
