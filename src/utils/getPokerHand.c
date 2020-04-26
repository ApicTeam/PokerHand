#include "methods.h"
#include "minilib.h"

t_pokerHand *get_poker_hand(char *poker_hand)
{

	/* Variable Definition */
    t_pokerHand *last_card = NULL;

    // TODO Free that memory
    char *rank = mx_strnew(100);
    char *suit = mx_strnew(100);

    int temp = 0;

	poker_hand = mx_del_extra_whitespaces(poker_hand);

	int temp_len = mx_strlen(poker_hand);

	/* Base Case */
	if (mx_count_words(poker_hand, ' ') != 5) raise_error(1, "NULL");

	/*
	 * Main Logic
	 * r is rank index
	 * s is suit index
	 * card_count counts card for loop and possible error check
	 */
    for (int r = 0, s = 0, card_count = 1; card_count <= 5;)
    {
		/*
		 * First if allocate ranks and suit
		 * Possible Fixes:
		 * Remove temp variable
		 */
        if (*poker_hand != ' ' && *poker_hand != '\0')
        {
            while (!mx_is_suit(*poker_hand) && temp == 0 && *poker_hand != '\0' && *poker_hand != ' ')
                rank[r] = *poker_hand++, r++;

			if (*poker_hand != ' ') {
				temp = 1;
				suit[s] = *poker_hand++, s++;
			}
        }

		/* Second if create nodes of list */
        else if (*poker_hand == ' ' || *poker_hand == '\0')
        {
            if (last_card == NULL)  // Creat first node if it is first data
            {
                last_card = mx_create_node(mx_strcpy(mx_strnew(mx_strlen(rank)), rank),
                                           mx_strcpy(mx_strnew(mx_strlen(suit)), suit));
                r = 0, s = 0, temp = 0, card_count++;
	            free(rank);
	            free(suit);
	            rank = mx_strnew(100);
	            suit = mx_strnew(100);
            }
            else // Create next node
            {
                mx_push_back(&last_card, mx_strcpy(mx_strnew(mx_strlen(rank)), rank),
                             mx_strcpy(mx_strnew(mx_strlen(suit)), suit));
                r = 0, s = 0, temp = 0, card_count++;
				free(rank);
				free(suit);
				rank = mx_strnew(100);
	            suit = mx_strnew(100);

            }
            poker_hand++;
        }
    }

	/* Garbage Collector */
	mx_strdel(&rank);
	mx_strdel(&suit);

	if (temp_len <= 13)
		temp_len += 1;

	for (int i = temp_len; i >= 0; i--)
		poker_hand--;

	mx_strdel(&poker_hand);

	return last_card;
}