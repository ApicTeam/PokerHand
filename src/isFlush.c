#include "minilibmx.h"

bool isFlush(const char *s){
	int curr = 0;
	int i = 0;
	while(i != 5){
		if(s[i] == s[i+1])
			curr++;
		i++;
	}
	return curr;
}

