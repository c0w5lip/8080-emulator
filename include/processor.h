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



const uint8_t lengths[256] = {
    1, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 1, 1, 1, 2, 1,
    1, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 1, 1, 1, 2, 1,
    1, 3, 3, 1, 1, 1, 2, 1, 1, 3, 3, 1, 1, 1, 2, 1,
    1, 3, 3, 1, 1, 1, 2, 1, 1, 3, 3, 1, 1, 1, 2, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 3, 3, 3, 1, 2, 1, 1, 1, 3, 3, 3, 3, 2, 1,
    1, 1, 3, 2, 3, 1, 2, 1, 1, 1, 3, 2, 3, 3, 2, 1,
    1, 1, 3, 1, 3, 1, 2, 1, 1, 1, 1, 3, 1, 3, 3, 2,
    1, 1, 3, 1, 3, 1, 2, 1, 1, 1, 1, 3, 1, 3, 3, 2
};


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
}

/* MOVS */

void MOV_BB(Processor *p) {
    puts("MOV_BB called");

    p->B = p->B;
}


void MOV_BC(Processor *p) {
    puts("MOV_BC called");

    p->B = p->C;
}


void MOV_BD(Processor *p) {
    puts("MOV_BD called");

    p->B = p->D;
}

void MOV_BE(Processor *p) {
    puts("MOV_BE called");

    p->B = p->E;
}

void MOV_BH(Processor *p) {
    puts("MOV_BH called");

    p->B = p->H;
}

void MOV_BL(Processor *p) {
    puts("MOV_BL called");

    p->B = p->L;
}

void MOV_BM(Processor *p) {
    puts("MOV_BM called");
    
    p->B = p->memory[(p->H >> 8) | (p->L)];
}

void MOV_BA(Processor *p) {
    puts("MOV_BA called");

    p->B = p->A;
}






void MOV_CB(Processor *p) {
    puts("MOV_CB called");

    p->C = p->B;
}

void MOV_CC(Processor *p) {
    puts("MOV_CC called");

    p->C = p->C;
}

void MOV_CD(Processor *p) {
    puts("MOV_CD called");

    p->C = p->D;
}

void MOV_CE(Processor *p) {
    puts("MOV_CE called");

    p->C = p->E;
}

void MOV_CH(Processor *p) {
    puts("MOV_CH called");

    p->C = p->H;
}

void MOV_CL(Processor *p) {
    puts("MOV_CL called");

    p->C = p->L;
}

void MOV_CM(Processor *p) {
    puts("MOV_CM called");

    p->C = p->memory[(p->H >> 8) | (p->L)];
}

void MOV_CA(Processor *p) {
    puts("MOV_CA called");

    p->C = p->A;
}


/* */

void LXI_SP(Processor *p) {
    puts("LXI_SP called");
}


void HTL(Processor *p) {
    p->is_halted = true;
}


void (*instructions[256])(Processor*) = {
    // 0x00 - 0x0f
    [0x00] = NOP,

    [0x40] = MOV_BB, [0x41] = MOV_BC, [0x42] = MOV_BD, [0x43] = MOV_BE, [0x44] = MOV_BH, [0X45] = MOV_BL, [0x46] = MOV_BM, [0x47] = MOV_BA,
    [0x48] = MOV_CB, [0x49] = MOV_CC, [0x4A] = MOV_CD, [0x4B] = MOV_CE, [0x4C] = MOV_CH, [0X4D] = MOV_CL, [0x4E] = MOV_CM, [0x4F] = MOV_CA,
    


    

    [0x31] = LXI_SP,

    [0x76] = HTL 
};