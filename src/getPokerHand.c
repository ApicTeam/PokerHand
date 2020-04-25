#include "methods.h"
#include "minilib.h"

t_pokerHand *get_poker_hand(const char *poker_hand)
{
    // TODO Add trim

    /* Variables Definitions */
    char temp_string[3];  // TODO Add malloc new str
    int card_status = 1;

    // TODO Free that malloc
    t_pokerHand *tPokerHand = malloc(sizeof(t_pokerHand));

    for (int card_size = 0; *poker_hand != '\0'; ++card_size)
    {

        if (*poker_hand == ' ')

            switch (card_status)
            {
                case 1:
                    card_size = 0;
                    card_status++;
                    tPokerHand -> c1 = temp_string;
                    break;

                case 2:
                    card_size = 0;
                    card_status++;
                    tPokerHand -> c2 = temp_string;
                    break;

                case 3:
                    card_size = 0;
                    card_status++;
                    tPokerHand -> c3 = temp_string;
                    break;

                case 4:
                    card_size = 0;
                    card_status++;
                    tPokerHand -> c4 = temp_string;
                    break;

                case 5:
                    card_size = 0;
                    card_status++;
                    tPokerHand -> c5 = temp_string;
                    break;

                default:
                    print_error(1, "NULL");
                    break;
            }

        if (card_size > 2)  // Kostyl Number: 0
        {
            print_error(3, temp_string);

            while (*poker_hand != ' ')
                write(1, &*poker_hand++, 1);

            write(1, "\n", 1);
            exit(1);
        }


        temp_string[card_size - 1] = poker_hand[card_size - 1];

    }

    return tPokerHand;
}