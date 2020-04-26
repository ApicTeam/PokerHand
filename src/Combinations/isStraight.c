#include "methods.h"
#include "minilib.h"

bool isStraight(t_pokerHand *hand)
{
	int i;

	hand = mx_sort_poker_hand(hand, byRank);
	t_pokerHand *last_card = get_last_card(hand);

	if (!mx_strcmp(last_card -> rank, "A"))
	{
		if (mx_strcmp(hand -> rank, "2")
					== mx_strcmp(hand -> next -> rank, "3")
			&&
			mx_strcmp(hand -> next -> next -> rank, "4")
					== mx_strcmp(hand -> next -> next -> next -> rank, "5"))
		{
//			print_result(6);
//			freeList(hand);
			return true;
		}
		else if (mx_strcmp(hand -> rank, "10")
		         == mx_strcmp(hand -> next -> rank, "J")
	         &&
	         mx_strcmp(hand -> next -> next -> rank, "Q")
		         == mx_strcmp(hand -> next -> next -> next -> rank, "K"))
		{
//			freeList(hand);
//			print_result(6);
			return true;
		}
	}
	else
	{

		for (i = 0; hand -> next != NULL; hand = hand -> next)
			if(generate_value(hand) == generate_value(hand -> next) - 1)
				i++;


		if (i == 4)
		{
//			freeList(hand);
//			print_result(6);
			return true;
		}
	}

	return false;
}