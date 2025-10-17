#include "../include/helpers.h"


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




void set_flag_zsp(Processor *p, uint8_t value) {
    p->F.Z = (value == 0);
    p->F.S = ((value & 0x80) == 0x80);
    p->F.P = is_even(value);
}


void update_flags_l(Processor *p) { // logical operations
    p->F.C = p->F.A = 0;
    set_flag_zsp(p, p->A);
}


void update_flags_a(Processor *p, uint16_t r) { // arithmetical operations
    p->F.C = (r > 0xFF);
    set_flag_zsp(p, r & 0xFF);
}

