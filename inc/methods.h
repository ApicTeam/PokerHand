#ifndef TEST_METHODS_H
#define TEST_METHODS_H

/* Includes */
#include <stdbool.h>
#include <stdlib.h>

/* Structures */
//typedef struct s_pokerHand
//{
//    char *c1;
//    char *c2;
//    char *c3;
//    char *c4;
//    char *c5;
//}              t_pokerHand;


typedef struct s_pokerHand
{
    char *rank;
    char *suit;
    struct s_pokerHand *next;
}              t_pokerHand;

typedef struct  s_card
{
	char *card;
	int value;
}               t_card;

/* Prototypes */
void raise_error(int error_id, char *value);
t_pokerHand *get_poker_hand(char *poker_hand);
char *mx_strcpy(char*dst, const char*src);
char *mx_del_extra_whitespaces(const char *str);
t_pokerHand *mx_create_node(char *rank, char *suit);
void mx_push_back(t_pokerHand **list, char *rank, char *suit);
bool is_suit(char *suit);
bool is_rank(char *rank);
void PokerHand(char *poker_hand);
t_pokerHand *mx_sort_poker_hand(t_pokerHand *list, bool(*cmp)(t_pokerHand *hand1, t_pokerHand *hand2));
bool byRank(t_pokerHand *hand1, t_pokerHand *hand2);
bool bySuit(t_pokerHand *hand1, t_pokerHand *hand2);
t_pokerHand *get_last_card(t_pokerHand *hand);
char *make_card(t_pokerHand *tPokerHand);
void print_result(int result_id);

/* Combinations */
bool isFlush(t_pokerHand *hand);
bool isStraight(t_pokerHand *hand);

/* Utils */
void DeletePokerHand(t_pokerHand *tPokerHand); // Garbage Collector
void freeList(t_pokerHand * head); // Garbage Collector
t_card *generate_card(t_pokerHand *hand);
int generate_value(t_pokerHand *hand);

#endif//TEST_METHODS_H
