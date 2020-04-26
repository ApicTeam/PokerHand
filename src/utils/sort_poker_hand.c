#include "minilib.h"
#include "methods.h"

bool byRank(t_pokerHand *hand1, t_pokerHand *hand2)
{
	char *lookup_table[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

	int value1 = 0;
	int value2 = 0;

	for (int i = 0; mx_strcmp(hand1 -> rank, lookup_table[i]); ++i, value1++);
	for (int i = 0; mx_strcmp(hand2 -> rank, lookup_table[i]); ++i, value2++);

	return value1 > value2;

}

bool bySuit(t_pokerHand *hand1, t_pokerHand *hand2)
{
	char *lookup_table[5] = {"H", "S", "C", "D"};

	int value1 = 0;
	int value2 = 0;

	for (int i = 0; mx_strcmp(hand1 -> suit, lookup_table[i]); ++i, value1++);
	for (int i = 0; mx_strcmp(hand2 -> suit, lookup_table[i]); ++i, value2++);

	return value1 > value2;
}


t_pokerHand *mx_sort_poker_hand(t_pokerHand *list, bool(*cmp)(t_pokerHand *hand1, t_pokerHand *hand2))
{
	if (!list) return NULL;

	for (t_pokerHand *i = list; i -> next != NULL; i = i -> next)
	{
		t_pokerHand *sorted = i;

		for (t_pokerHand *j = i -> next; j != NULL; j = j -> next)
			if (cmp(sorted, j))
				sorted = j;


		void *temp_rank = sorted -> rank;
		void *temp_suit = sorted -> suit;
		sorted -> rank = i -> rank;
		sorted -> suit = i -> suit;
		i -> rank = temp_rank;
		i -> suit = temp_suit;
	}
	return list;
}