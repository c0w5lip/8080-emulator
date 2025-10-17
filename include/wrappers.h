#ifndef WRAPPERS_H
#define WRAPPERS_H

#include "processor.h"


void push(Processor *p, uint8_t h, uint8_t l);
void pop(Processor *p, uint8_t *h, uint8_t *l);

void add(Processor *p, uint8_t r);
void ana(Processor *p, uint8_t r);
void sub(Processor *p, uint8_t r);
void sbb(Processor *p, uint8_t r);
void adc(Processor *p, uint8_t r);
void xra(Processor *p, uint8_t r);
void ora(Processor *p, uint8_t r);

void cmp(Processor *p, uint8_t r);

void inr(Processor *p, uint8_t *r);
void dcr(Processor *p, uint8_t *r);

#endif