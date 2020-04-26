#include "methods.h"

bool is22s(t_pokerHand *hand)
{

	if ( is4s(hand) || isFullHouse(hand) || is3s(hand) )
		return(false);

	hand = mx_sort_poker_hand(hand, byRank);

	if (hand -> rank[0] == hand -> next -> rank[0]
		&&
		hand -> next -> next -> rank[0] == hand -> next -> next -> next -> rank[0])
	return true;

	else if (hand -> rank[0] == hand -> next -> rank[0]
	    &&
	    hand -> next -> next -> next -> rank[0] ==
					 hand -> next -> next -> next -> next -> rank[0])
	return true;

	else if (hand -> next -> rank[0] == hand -> next -> next -> rank[0]
	         &&
	         hand -> next -> next -> next -> rank[0] ==
	         hand -> next -> next -> next -> next -> rank[0])
	return true;

	return false;
}