#include "minilib.h"
#include "methods.h"

bool byRank(t_pokerHand *hand1, t_pokerHand *hand2)
{
	char *lookup_table[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

	int value1 = 0;
	int value2 = 0;

	for (int i = 0; mx_strcmp(hand1 -> rank, lookup_table[i]); ++i, value1++);
	for (int i = 0; mx_strcmp(hand2 -> rank, lookup_table[i]); ++i, value2++);

	return value1 > value2;

}

bool bySuit(t_pokerHand *hand1, t_pokerHand *hand2)
{
	char *lookup_table[5] = {"H", "S", "C", "D"};

	int value1 = 0;
	int value2 = 0;

	for (int i = 0; mx_strcmp(hand1 -> suit, lookup_table[i]); ++i, value1++);
	for (int i = 0; mx_strcmp(hand2 -> suit, lookup_table[i]); ++i, value2++);

	return value1 > value2;
}


t_pokerHand *mx_sort_poker_hand(t_pokerHand *list, bool(*cmp)(t_pokerHand *hand1, t_pokerHand *hand2)){
	t_pokerHand *ptr = list;
	t_pokerHand *temp = ptr;
	bool swapped = true;

	while(swapped)
	{
		swapped = false;

		while(ptr->next)
		{
			if(cmp(ptr, ptr->next))
			{
				if(temp != ptr && ptr->next->next)
				{
					temp->next = ptr->next;
					ptr->next = ptr->next->next;
					temp->next->next = ptr;
					swapped = true;
				}
				else if(temp == ptr && ptr->next)
				{
					ptr = ptr->next;
					temp->next = ptr->next;
					ptr->next = temp;
					list = ptr;
					swapped = true;
				}
				else
				{
					temp->next = ptr->next;
					temp->next->next = ptr;
					ptr->next = NULL;
				}
			}
			temp = ptr;
			if(ptr->next)
				ptr = ptr->next;
		}
		ptr = list;
		temp = ptr;
	}

	return list;
}