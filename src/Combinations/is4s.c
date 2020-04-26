#include "methods.h"

bool is4s(t_pokerHand *hand)
{
	int value = 0;
	int base_value = generate_value(hand);
	hand = mx_sort_poker_hand(hand, byRank);

	if (generate_value(hand) == generate_value(hand -> next))
		for (; hand -> next -> next != NULL; hand = hand -> next)
			value += generate_value(hand);
	else
		for (hand = hand -> next; hand != NULL; hand = hand -> next)
			value += generate_value(hand);

	if (value / 4 == base_value)
		return true;

	return false;
}
