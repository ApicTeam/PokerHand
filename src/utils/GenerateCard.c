#include <methods.h>
#include <minilib.h>

//t_card *generate_card(t_pokerHand *hand)
//{
//	t_card *card = malloc(sizeof(t_card));
//	int card_string_size = mx_strlen(hand -> rank) + mx_strlen(hand -> suit);
//	card -> card = mx_strnew(card_string_size + 1);
//
//	card -> card = mx_strcat(card -> card, hand -> rank);
//	card -> card = mx_strcat(card -> card, hand -> suit);
//
//	char *lookup_table[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
//
//	for (int i = 0; mx_strcmp(hand -> rank, lookup_table[i]); ++i, card -> value++);
//
//	return card;
//}

int generate_value(t_pokerHand *hand)
{
	if (hand == NULL)
		return 0;

	int value = 0;

	char *lookup_table[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
	for (int i = 0; mx_strcmp(hand -> rank, lookup_table[i]); ++i, value++);

	return value;
}