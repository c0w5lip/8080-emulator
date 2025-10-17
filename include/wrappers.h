#ifndef WRAPPERS_H
#define WRAPPERS_H

#include "../include/processor.h"


void push(Processor *p, uint8_t h, uint8_t l);
void pop(Processor *p, uint8_t *h, uint8_t *l);

void add(Processor *p, uint8_t r);
void sub(Processor *p, uint8_t r);
void sbb(Processor *p, uint8_t r);
void adc(Processor *p, uint8_t r);

void inr(Processor *p, uint8_t *r);
void dcr(Processor *p, uint8_t *r);

void set_flag_zsp(Processor *p, uint8_t value);

void update_flags_l(Processor *p);
void update_flags_a(Processor *p, uint16_t r); 

#endif