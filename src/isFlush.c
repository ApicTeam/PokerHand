#include "methods.h"
#include "minilib.h"

void isFlush(t_pokerHand *hand)
{
	/*
	 * Сортируем масив по мастям и проверям если
	 * масть последеней карты равна масте первой значит Флеш
	 */
	mx_sort_poker_hand(hand, bySuit);
	t_pokerHand *last_card = get_last_card(hand);

	if(mx_strcmp(hand -> suit, last_card -> suit) == 0)
		print_result(5);
}

