#include "methods.h"
bool isFullHouse(t_pokerHand *hand)
{
	hand = mx_sort_poker_hand(hand, byRank);

	if (hand -> rank[0] ==
				hand -> next -> rank[0]
		&&
		hand -> next -> rank[0] ==
				hand -> next -> next -> rank[0]
		&&
		hand -> next -> next -> next -> rank[0] ==
				hand -> next -> next -> next -> next -> rank[0])
		return true;

	else if(hand -> rank[0] ==
					 hand -> next -> rank[0]
			 &&
		    hand -> next -> next -> rank[0]
					 == hand -> next -> next -> next -> rank[0]
			 &&
			hand -> next -> next -> next -> rank[0] ==
					hand -> next -> next -> next -> next -> rank[0])
		return true;

	return false;
}