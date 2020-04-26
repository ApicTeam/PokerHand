#include "methods.h"
#include "minilib.h"

bool is4s(t_pokerHand *hand)
{
	hand = mx_sort_poker_hand(hand, byRank);
}
