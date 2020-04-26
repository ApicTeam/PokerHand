#include "methods.h"
#include "minilib.h"

char *make_card(t_pokerHand *tPokerHand) {

	// TODO Free that memory
	char *card = mx_strnew(mx_strlen(tPokerHand->rank) + mx_strlen(tPokerHand->suit));

	card = mx_strcat(card, tPokerHand->rank);
	card = mx_strcat(card, tPokerHand->suit);

	return card;
}

void check_duplicate(t_pokerHand *tPokerHand) {
	tPokerHand = mx_sort_poker_hand(tPokerHand,  byRank);
	for (; tPokerHand->next->next != NULL; tPokerHand = tPokerHand->next)
		if (mx_strcmp(tPokerHand->suit, tPokerHand->next->suit) == 0 &&
		    mx_strcmp(tPokerHand->rank, tPokerHand->next->rank) == 0)
			raise_error(2, make_card(tPokerHand));
}

void check_hand(t_pokerHand *tPokerHand) {
	while (tPokerHand != NULL) {
		if (!is_suit(tPokerHand->suit) && !is_rank(tPokerHand->rank) && mx_strlen(make_card(tPokerHand)) == 1)
			raise_error(3, make_card(tPokerHand));
		else if (!is_suit(tPokerHand->suit))
			raise_error(4, make_card(tPokerHand));
		else if (!is_rank(tPokerHand->rank))
			raise_error(5, make_card(tPokerHand));
		tPokerHand = tPokerHand->next;
	}
}

void PokerHand(char *poker_hand) {
	/* Variable Definitions */
	t_pokerHand *tPokerHand = get_poker_hand(poker_hand);

	/* Checks */
	check_duplicate(tPokerHand);
	check_hand(tPokerHand);

	/* Combinations */
	if (isFlush(tPokerHand) && isStraight(tPokerHand) && get_last_card(tPokerHand) -> rank[0] == 'A')
	{
		print_result(1);
		freeList(tPokerHand);
	}
	else if(isFlush(tPokerHand) && isStraight(tPokerHand))
	{
		print_result(2);
		freeList(tPokerHand);
	}
	else if(is4s(tPokerHand))
	{
		print_result(3);
		freeList(tPokerHand);
	}

	tPokerHand = get_poker_hand(poker_hand);

	if(isFullHouse(tPokerHand))
	{
		print_result(4);
		freeList(tPokerHand);
	}

	else if (isFlush(tPokerHand))
	{
		print_result(5);
		freeList(tPokerHand);
	}

	tPokerHand = get_poker_hand(poker_hand);

	if (isStraight(tPokerHand))
	{
		print_result(6);
		freeList(tPokerHand);
	}

	tPokerHand = get_poker_hand(poker_hand);

	if (is3s(tPokerHand))
	{
		print_result(7);
		freeList(tPokerHand);
	}

	if (is22s(tPokerHand))
	{
		print_result(8);
		freeList(tPokerHand);
	}

	if(is2s(tPokerHand))
	{
		print_result(9);
		freeList(tPokerHand);
	}

	print_result(10);
	freeList(tPokerHand);


}
