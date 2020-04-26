#include "methods.h"
#include "minilib.h"

void generate_size(t_pokerHand *tPokerHand)
{
    // TODO Free that memory;

    tPokerHand -> c1 = mx_strnew(3);
    tPokerHand -> c2 = mx_strnew(3);
    tPokerHand -> c3 = mx_strnew(3);
    tPokerHand -> c4 = mx_strnew(3);
    tPokerHand -> c5 = mx_strnew(3);
}

t_pokerHand *get_poker_hand(const char *poker_hand)
{
    /* Variables Definitions */
    char *temp_string = mx_strnew(3);  // TODO Free that malloc
    int card_status = 1;

    /* Deletes spaces from input string */
    poker_hand = mx_del_extra_whitespaces(poker_hand);

    // TODO Free that malloc
    t_pokerHand *tPokerHand = malloc(sizeof(t_pokerHand));
    generate_size(tPokerHand);

    /*
     * Main Logic
     * card_size == numbers of char for temp_string
     * if card_size bigger then 1 error msg will display
     */
    for (int card_size = 0; *poker_hand != '\0'; card_size++)
    {

        /*
         * Logic for Invalid Card Error
         * Raise error with code 3 eg. Invalid Card: <value>
         * Send to print_error args: err_id and value of temp_string
         * Then iterate to next space and print all of unsuspected char
         */
        if (card_size > 1)  // Kostyl Number: 0
        {
            print_error(3, temp_string);

            while (*poker_hand != ' ')
                write(2, &*poker_hand++, 1);

            write(2, "\n", 1);
            exit(1);
        }

        /* Add char to temp_string and moves forward pointer of poker_hand */
        temp_string[card_size] = *poker_hand;
        poker_hand++;

        /* Fill up poker_hand struct each card
         * if card_status more then 5
         * Raise error of usage(err_id = 1)
         */
        if (*poker_hand == ' ' || *poker_hand == '\0')

            switch (card_status)
            {
            case 1:
              card_size = -1;
              card_status++;
              poker_hand++;
              mx_strcpy(tPokerHand -> c1, temp_string);
              mx_strdel(&temp_string);
              temp_string = mx_strnew(3);
              break;

            case 2:
              card_size = -1;
              card_status++;
              poker_hand++;
              mx_strcpy(tPokerHand -> c2, temp_string);
              mx_strdel(&temp_string);
              temp_string = mx_strnew(3);
              break;

            case 3:
              card_size = -1;
              card_status++;
              poker_hand++;
              mx_strcpy(tPokerHand -> c3, temp_string);
              mx_strdel(&temp_string);
              temp_string = mx_strnew(3);
              break;

            case 4:
              card_size = -1;
              card_status++;
              poker_hand++;
              mx_strcpy(tPokerHand -> c4, temp_string);
              mx_strdel(&temp_string);
              temp_string = mx_strnew(3);
              break;

            case 5:
              card_size = -1;
              card_status++;
              poker_hand++;
              mx_strcpy(tPokerHand -> c5, temp_string);
              mx_strdel(&temp_string);
              temp_string = mx_strnew(3);
              break;

            default:
              print_error(1, "NULL");
              break;
            }
      }

      free(temp_string);
      temp_string = NULL;

      return tPokerHand;
}