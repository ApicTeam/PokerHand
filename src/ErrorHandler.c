#include "minilib.h"

void print_error(int error_id, char *value)
{
    /* Variable Definitions */
    char *error_msg;

    switch (error_id)
    {
        case 1:
            error_msg = "usage: ./race03 [card1] [card2] [card3] [card4] [card5]\n";
            write(2, error_msg, mx_strlen(error_msg));
            exit(1);

        case 2:
            error_msg = "Duplicate cards: ";
            write(2, error_msg, mx_strlen(error_msg));
            write(2, value, mx_strlen(value));
            break;

        case 3:
            error_msg = "Invalid card: ";
            write(2, error_msg, mx_strlen(error_msg));
            write(2, value, mx_strlen(value));
            break;

        case 4:
            error_msg = "Invalid card suit: ";
            write(2, error_msg, mx_strlen(error_msg));
            write(2, value, mx_strlen(value));
            break;

        case 5:
            error_msg = "Invalid card rank: ";
            write(2, error_msg, mx_strlen(error_msg));
            write(2, value, mx_strlen(value));
            break;

        default:
            break;
    }
}