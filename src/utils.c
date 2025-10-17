#include "../include/utils.h"

int is_even(int a) {
	int b = 0;
	a = (a & ((1 << 8) - 1));
	for(int i = 0; i < 8; i++) {
		if(a & 0x1) 
			b++;
		a = a >> 1;	
	}

	return (0 == (b & 0x1));
}
