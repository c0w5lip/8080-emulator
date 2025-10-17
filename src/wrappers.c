#include <stdlib.h>

#include "../include/wrappers.h"



void push(Processor *p, uint8_t h, uint8_t l) {
    p->memory[(p->SP)-1] = h;
    p->memory[(p->SP)-2] = l;

    p->SP -= 2;
}

void pop(Processor *p, uint8_t *h, uint8_t *l) {
    h = p->memory[(p->SP)+1];
    l = p->memory[p->SP];

    p->SP += 2;
}




void add(Processor *p, uint8_t r) {
    uint16_t result = (uint16_t) p->A + (uint16_t) r;

    p->F.S = (0x80 == (result & 0x80));
    p->F.Z = ((result & 0xFF) == 0);
    p->F.A = (result & 0xFF);
    p->F.P = is_even(result & 0xFF);
    p->F.C = (result > 0xFF);
}


void sub(Processor *p, uint8_t r) {
    uint16_t result = (uint16_t) p->A - (uint16_t) r;

    update_flags_a(p, r);
    p->A = result & 0xFF;
}

void sbb(Processor *p, uint8_t r) {
    uint16_t result = (uint16_t) p->A - (uint16_t) r - p->F.C;

    update_flags_a(p, r);
    p->A = result & 0xFF;
}




void adc(Processor *p, uint8_t r) {
    uint16_t result = (uint16_t) p->A + (uint16_t) r;

    update_flags_a(p, r);
    p->A = result & 0xFF;
}


void inr(Processor *p, uint8_t *r) {
    uint8_t result = *r + 1;
    set_flag_zsp(p, result);
    *r = result;
}


void dcr(Processor *p, uint8_t *r) {
    uint8_t result = *r - 1;
    set_flag_zsp(p, result);
    *r = result;
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

