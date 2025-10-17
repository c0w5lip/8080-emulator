#ifndef HELPERS_H
#define HELPERS_H

#include "processor.h"

int is_even(int i);

void set_flag_zsp(Processor *p, uint8_t value);

void update_flags_l(Processor *p);
void update_flags_a(Processor *p, uint16_t r); 

#endif