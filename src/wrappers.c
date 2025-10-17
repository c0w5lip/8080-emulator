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


void ana(Processor *p, uint8_t r) {
    p->A = p->A & r;

    p->F.S = (0x80 == (p->A & 0x80));
    p->F.Z = ((p->A & 0xFF) == 0);
    p->F.P = is_even(p->A & 0xFF);
    p->F.C = 0;
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


void xra(Processor *p, uint8_t r) {
    p->A = p->A ^ r;

    update_flags_l(p);
}



void ora(Processor *p, uint8_t r) {
    p->A = p->A | r;

    update_flags_l(p);
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










