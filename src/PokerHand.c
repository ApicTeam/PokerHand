#include "methods.h"
#include "minilib.h"

char *make_card(t_pokerHand *tPokerHand)
{

	// TODO Free that memory
	char *card = mx_strnew(mx_strlen(tPokerHand -> rank) + mx_strlen(tPokerHand -> suit));

	card = mx_strcat(card, tPokerHand -> rank);
	card = mx_strcat(card, tPokerHand -> suit);

	return card;

}

void check_duplicate(t_pokerHand *tPokerHand)
{
	for (;tPokerHand -> next -> next != NULL; tPokerHand = tPokerHand -> next)
		if (mx_strcmp(tPokerHand -> suit, tPokerHand -> next -> suit) == 0
			&&
			mx_strcmp(tPokerHand -> rank, tPokerHand -> next -> rank) == 0)
			raise_error(2, make_card(tPokerHand));

}

void check_hand(t_pokerHand *tPokerHand)
{
	while (tPokerHand != NULL)
	{
		if (!is_suit(tPokerHand -> suit) && !is_rank(tPokerHand -> rank) && mx_strlen(make_card(tPokerHand)) == 1)
			raise_error(3, make_card(tPokerHand));
		else if(!is_suit(tPokerHand -> suit)) raise_error(4, make_card(tPokerHand));
		else if(!is_rank(tPokerHand -> rank)) raise_error(5, make_card(tPokerHand));
		tPokerHand = tPokerHand -> next;
	}

}

void PokerHand(char *poker_hand)
{
	/* Variable Definitions */
    t_pokerHand *tPokerHand = get_poker_hand(poker_hand);

	/* Checks */
	check_duplicate(tPokerHand);
	check_hand(tPokerHand);

	make_card(tPokerHand);

}
