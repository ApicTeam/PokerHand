#include "methods.h"

void freeList(t_pokerHand * head)
{
	t_pokerHand* tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head -> next;
		free(tmp -> suit);
		tmp -> suit = NULL;
		free(tmp -> rank);
		tmp -> rank = NULL;
		tmp -> next = NULL;
		free(tmp);
	}

}