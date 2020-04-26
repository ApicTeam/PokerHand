#include "minilib.h"

void print_result(int result_id)
{
	switch (result_id)
	{
		case 1:
			mx_printstr("Royal flush");
			break;

		case 2:
			mx_printstr("Straight flush");
			break;

		case 3:
			mx_printstr("Four of a kind");
			break;

		case 4:
			mx_printstr("Full house");
			break;

		case 5:
			mx_printstr("Flush");
			break;

		case 6:
			mx_printstr("Straight");
			break;

		case 7:
			mx_printstr("Three of a kind");
			break;

		case 8:
			mx_printstr("Two pair");
			break;

		case 9:
			mx_printstr("One pair");
			break;

		case 10:
			mx_printstr("No pair");
			break;

		default:
			break;
	}
}