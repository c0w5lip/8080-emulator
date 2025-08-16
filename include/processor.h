#pragma once

#include <stdint.h>
#include <stdbool.h>


typedef struct Flags
{
    uint8_t S:1;
    uint8_t Z:1;
    uint8_t A:1;
    uint8_t P:1;
    uint8_t C:1;

    uint8_t padding:3;
} Flags;

typedef struct Processor
{
    uint8_t A, B, C, D, E, H, L;
    uint16_t SP;
    uint16_t PC;

    Flags F;
    uint8_t *memory;

    bool is_halted;

    uint64_t cycle_count;
} Processor;


const uint8_t cycles[256] = {
    4, 10, 7, 5, 5, 5, 7, 4, 4, 10, 7, 5, 5, 5, 7, 4,
	4, 10, 7, 5, 5, 5, 7, 4, 4, 10, 7, 5, 5, 5, 7, 4,
	4, 10, 16, 5, 5, 5, 7, 4, 4, 10, 16, 5, 5, 5, 7, 4,
	4, 10, 13, 5, 10, 10, 10, 4, 4, 10, 13, 5, 5, 5, 7, 4,
	5, 5, 5, 5, 5, 5, 7, 5, 5, 5, 5, 5, 5, 5, 7, 5,
	5, 5, 5, 5, 5, 5, 7, 5, 5, 5, 5, 5, 5, 5, 7, 5,
	5, 5, 5, 5, 5, 5, 7, 5, 5, 5, 5, 5, 5, 5, 7, 5,
	7, 7, 7, 7, 7, 7, 7, 7, 5, 5, 5, 5, 5, 5, 7, 5,
	4, 4, 4, 4, 4, 4, 7, 4, 4, 4, 4, 4, 4, 4, 7, 4,
	4, 4, 4, 4, 4, 4, 7, 4, 4, 4, 4, 4, 4, 4, 7, 4,
	4, 4, 4, 4, 4, 4, 7, 4, 4, 4, 4, 4, 4, 4, 7, 4,
	4, 4, 4, 4, 4, 4, 7, 4, 4, 4, 4, 4, 4, 4, 7, 4,
	11, 10, 10, 10, 17, 11, 7, 11, 11, 10, 10, 10, 10, 17, 7, 11,
	11, 10, 10, 10, 17, 11, 7, 11, 11, 10, 10, 10, 10, 17, 7, 11, 
	11, 10, 10, 18, 17, 11, 7, 11, 11, 5, 10, 5, 17, 17, 7, 11, 
	11, 10, 10, 4, 17, 11, 7, 11, 11, 5, 10, 4, 17, 17, 7, 11
};


void NOP(Processor *p) {
    puts("NOP called");

    p->PC++;
}


void MOV_BB(Processor *p) {
    puts("MOV_BB called");

    p->B = p->B;

    p->PC++;
}


void MOV_BC(Processor *p) {
    puts("MOV_BC called");

    p->B = p->C;

    p->PC++;
}


void MOV_BD(Processor *p) {
    puts("MOV_BD called");

    p->B = p->D;

    p->PC++;
}

void LXI_SP(Processor *p) {
    puts("LXI_SP called");


    p->PC += 3;
}


void HTL(Processor *p) {
    p->is_halted = true;

    p->PC++;
}


void (*instructions[256])(Processor*) = {
    // 0x00 - 0x0f
    [0x00] = NOP,

    [0x40] = MOV_BB,
    [0x41] = MOV_BC,
    [0x42] = MOV_BD,

    [0x31] = LXI_SP,

    [0x76] = HTL 
};