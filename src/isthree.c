#include "minilib.h"

bool isthree(const int *s){
	int len = 0;
	int curr = 0;
	for(int j = 0; s[j] != '\0'; j++)
		len++;
	for(int i = 0; i < len; i++)
		for(int j = i+1; j < len; j++)
			if(s[i] == s[j])
				curr++;
	return curr == 3;
}

