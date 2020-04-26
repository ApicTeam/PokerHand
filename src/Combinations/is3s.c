#include <methods.h>

bool is3s(t_pokerHand *hand)
{
	hand = mx_sort_poker_hand(hand, byRank);

	if (hand -> rank[0] == hand -> next -> rank[0]
		&&
		hand -> next -> rank[0] == hand -> next -> next -> rank[0]
		&&
		hand -> next -> next -> next -> rank[0] != hand -> rank[0]
		&&
		hand -> next -> next -> next -> next -> rank[0] != hand -> rank[0]
		&&
		hand -> next -> next -> next -> rank[0] !=
				hand -> next -> next -> next -> next -> rank[0])
		return true;

	else if (hand -> next -> rank[0] == hand -> next -> next -> rank[0]
			 &&
			 hand -> next -> next -> rank[0] == hand -> next -> next -> next -> rank[0]
			 &&
			 hand -> rank[0] != hand -> next -> rank[0]
			 &&
			 hand -> next -> next -> next -> next -> rank[0] != hand -> next -> rank[0]
			 &&
			 hand -> rank[0] != hand -> next -> next -> next -> next -> rank[0])
		return true;

	else if (hand -> next -> next -> rank[0] == hand -> next -> next -> next -> rank[0]
			 &&
			 hand -> next -> next -> next -> rank[0] == hand -> next -> next -> next -> next -> rank[0]
			 &&
			 hand -> rank[0] != hand -> next -> next -> rank[0]
			 &&
			 hand -> next -> rank[0] != hand -> next -> next -> rank[0]
			 &&
			 hand -> rank[0] != hand -> next -> rank[0])
		return true;

	return false;
}