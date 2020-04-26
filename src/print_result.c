#include "minilib.h"

void print_result(int result_id)
{
	switch (result_id)
	{
		case 1:
			mx_printstr("Royal flush");
			exit(0);

		case 2:
			mx_printstr("Straight flush");
			exit(0);

		case 3:
			mx_printstr("Four of a kind");
			exit(0);

		case 4:
			mx_printstr("Full house");
			exit(0);

		case 5:
			mx_printstr("Flush");
			exit(0);

		case 6:
			mx_printstr("Straight");
			exit(0);

		case 7:
			mx_printstr("Two pair");
			exit(0);

		case 8:
			mx_printstr("One pair");
			exit(0);

		case 9:
			mx_printstr("No pair");
			exit(0);

		default:
			break;
	}
}