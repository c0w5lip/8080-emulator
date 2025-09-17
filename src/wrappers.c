#include <stdlib.h>

#include "../include/wrappers.h"

void add(Processor *p, uint8_t r) {
    uint16_t result = (uint16_t) p->A + (uint16_t) r;

    p->F.S = (0x80 == (result & 0x80));
    p->F.Z = ((result & 0xFF) == 0);
    p->F.A = (result & 0xFF);
    p->F.P = is_even(result & 0xFF);
    p->F.C = (result > 0xFF);
}
