#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <stdint.h>
#include <stdbool.h>

#include "helpers.h"
#include "wrappers.h"

typedef struct Flags {
    uint8_t S:1;
    uint8_t Z:1;
    uint8_t A:1;
    uint8_t P:1;
    uint8_t C:1;

    uint8_t padding:3;
} Flags;

typedef struct Processor {
    uint8_t A, B, C, D, E, H, L;
    uint16_t SP;
    uint16_t PC;

    Flags F;
    uint8_t *memory;

    bool is_halted;
    bool interrupts_enabled;

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


// function declarations here


void (*instructions[256])(Processor*) = {
    /* 0x00 - 0x0F */
    [0x00] = NOP, [0x01] = LXI_B, [0x02] = STAX_B, [0x03] = INX_B,
    [0x04] = INR_B, [0x05] = DCR_B, [0x06] = MVI_B, [0x07] = RLC,
    [0x08] = NOP, [0x09] = DAD_B, [0x0A] = LDAX_B, [0x0B] = DCX_B,
    [0x0C] = INR_C, [0x0D] = DCR_C, [0x0E] = MVI_C, [0x0F] = RRC,

    /* 0x10 - 0x1F */
    [0x10] = NOP, [0x11] = LXI_D, [0x12] = STAX_D, [0x13] = INX_D,
    [0x14] = INR_D, [0x15] = DCR_D, [0x16] = MVI_D, [0x17] = RAL,
    [0x18] = NOP, [0x19] = DAD_D, [0x1A] = LDAX_D, [0x1B] = DCX_D,
    [0x1C] = INR_E, [0x1D] = DCR_E, [0x1E] = MVI_E, [0x1F] = RAR,

    /* 0x20 - 0x2F */
    [0x20] = NOP, [0x21] = LXI_H, [0x22] = SHLD, [0x23] = INX_H,
    [0x24] = INR_H, [0x25] = DCR_H, [0x26] = MVI_H, [0x27] = DAA,
    [0x28] = NOP, [0x29] = DAD_H, [0x2A] = LHLD, [0x2B] = DCX_H,
    [0x2C] = INR_L, [0x2D] = DCR_L, [0x2E] = MVI_L, [0x2F] = CMA,

    /* 0x30 - 0x3F */
    [0x30] = NOP, [0x31] = LXI_SP, [0x32] = STA, [0x33] = INX_SP,
    [0x34] = INR_M, [0x35] = DCR_M, [0x36] = MVI_M, [0x37] = STC,
    [0x38] = NOP, [0x39] = DAD_SP, [0x3A] = LDA, [0x3B] = DCX_SP,
    [0x3C] = INR_A, [0x3D] = DCR_A, [0x3E] = MVI_A, [0x3F] = CMC,

    /* 0x40 - 0x4F */
    [0x40] = MOV_B_B, [0x41] = MOV_B_C, [0x42] = MOV_B_D, [0x43] = MOV_B_E,
    [0x44] = MOV_B_H, [0x45] = MOV_B_L, [0x46] = MOV_B_M, [0x47] = MOV_B_A,
    [0x48] = MOV_C_B, [0x49] = MOV_C_C, [0x4A] = MOV_C_D, [0x4B] = MOV_C_E,
    [0x4C] = MOV_C_H, [0x4D] = MOV_C_L, [0x4E] = MOV_C_M, [0x4F] = MOV_C_A,

    /* 0x50 - 0x5F */
    [0x50] = MOV_D_B, [0x51] = MOV_D_C, [0x52] = MOV_D_D, [0x53] = MOV_D_E,
    [0x54] = MOV_D_H, [0x55] = MOV_D_L, [0x56] = MOV_D_M, [0x57] = MOV_D_A,
    [0x58] = MOV_E_B, [0x59] = MOV_E_C, [0x5A] = MOV_E_D, [0x5B] = MOV_E_E,
    [0x5C] = MOV_E_H, [0x5D] = MOV_E_L, [0x5E] = MOV_E_M, [0x5F] = MOV_E_A,

    /* 0x60 - 0x6F */
    [0x60] = MOV_H_B, [0x61] = MOV_H_C, [0x62] = MOV_H_D, [0x63] = MOV_H_E,
    [0x64] = MOV_H_H, [0x65] = MOV_H_L, [0x66] = MOV_H_M, [0x67] = MOV_H_A,
    [0x68] = MOV_L_B, [0x69] = MOV_L_C, [0x6A] = MOV_L_D, [0x6B] = MOV_L_E,
    [0x6C] = MOV_L_H, [0x6D] = MOV_L_L, [0x6E] = MOV_L_M, [0x6F] = MOV_L_A,

    /* 0x70 - 0x7F */
    [0x70] = MOV_M_B, [0x71] = MOV_M_C, [0x72] = MOV_M_D, [0x73] = MOV_M_E,
    [0x74] = MOV_M_H, [0x75] = MOV_M_L, [0x76] = HLT, [0x77] = MOV_M_A,
    [0x78] = MOV_A_B, [0x79] = MOV_A_C, [0x7A] = MOV_A_D, [0x7B] = MOV_A_E,
    [0x7C] = MOV_A_H, [0x7D] = MOV_A_L, [0x7E] = MOV_A_M, [0x7F] = MOV_A_A,

    /* 0x80 - 0x8F */
    [0x80] = ADD_B, [0x81] = ADD_C, [0x82] = ADD_D, [0x83] = ADD_E,
    [0x84] = ADD_H, [0x85] = ADD_L, [0x86] = ADD_M, [0x87] = ADD_A,
    [0x88] = ADC_B, [0x89] = ADC_C, [0x8A] = ADC_D, [0x8B] = ADC_E,
    [0x8C] = ADC_H, [0x8D] = ADC_L, [0x8E] = ADC_M, [0x8F] = ADC_A,

    /* 0x90 - 0x9F */
    [0x90] = SUB_B, [0x91] = SUB_C, [0x92] = SUB_D, [0x93] = SUB_E,
    [0x94] = SUB_H, [0x95] = SUB_L, [0x96] = SUB_M, [0x97] = SUB_A,
    [0x98] = SBB_B, [0x99] = SBB_C, [0x9A] = SBB_D, [0x9B] = SBB_E,
    [0x9C] = SBB_H, [0x9D] = SBB_L, [0x9E] = SBB_M, [0x9F] = SBB_A,

    /* 0xA0 - 0xAF */
    [0xA0] = ANA_B, [0xA1] = ANA_C, [0xA2] = ANA_D, [0xA3] = ANA_E,
    [0xA4] = ANA_H, [0xA5] = ANA_L, [0xA6] = ANA_M, [0xA7] = ANA_A,
    [0xA8] = XRA_B, [0xA9] = XRA_C, [0xAA] = XRA_D, [0xAB] = XRA_E,
    [0xAC] = XRA_H, [0xAD] = XRA_L, [0xAE] = XRA_M, [0xAF] = XRA_A,

    /* 0xB0 - 0xBF */
    [0xB0] = ORA_B, [0xB1] = ORA_C, [0xB2] = ORA_D, [0xB3] = ORA_E,
    [0xB4] = ORA_H, [0xB5] = ORA_L, [0xB6] = ORA_M, [0xB7] = ORA_A,
    [0xB8] = CMP_B, [0xB9] = CMP_C, [0xBA] = CMP_D, [0xBB] = CMP_E,
    [0xBC] = CMP_H, [0xBD] = CMP_L, [0xBE] = CMP_M, [0xBF] = CMP_A,

    /* 0xC0 - 0xCF */
    [0xC0] = RNZ, [0xC1] = POP_B, [0xC2] = JNZ, [0xC3] = JMP,
    [0xC4] = CNZ, [0xC5] = PUSH_B, [0xC6] = ADI, [0xC7] = RST_0,
    [0xC8] = RZ, [0xC9] = RET, [0xCA] = JZ, [0xCB] = JMP,
    [0xCC] = CZ, [0xCD] = CALL, [0xCE] = ACI, [0xCF] = RST_1,

    /* 0xD0 - 0xDF */
    [0xD0] = RNC, [0xD1] = POP_D, [0xD2] = JNC, [0xD3] = OUT,
    [0xD4] = CNC, [0xD5] = PUSH_D, [0xD6] = SUI, [0xD7] = RST_2,
    [0xD8] = RC, [0xD9] = RET, [0xDA] = JC, [0xDB] = IN,
    [0xDC] = CC, [0xDD] = CALL, [0xDE] = SBI, [0xDF] = RST_3,

    /* 0xE0 - 0xEF */
    [0xE0] = RPO, [0xE1] = POP_H, [0xE2] = JPO, [0xE3] = XTHL,
    [0xE4] = CPO, [0xE5] = PUSH_H, [0xE6] = ANI, [0xE7] = RST_4,
    [0xE8] = RPE, [0xE9] = PCHL, [0xEA] = JPE, [0xEB] = XCHG,
    [0xEC] = CPE, [0xED] = CALL, [0xEE] = XRI, [0xEF] = RST_5,

    /* 0xF0 - 0xFF */
    [0xF0] = RP, [0xF1] = POP_PSW, [0xF2] = JP, [0xF3] = DI,
    [0xF4] = CP, [0xF5] = PUSH_PSW, [0xF6] = ORI, [0xF7] = RST_6,
    [0xF8] = RM, [0xF9] = SPHL, [0xFA] = JM, [0xFB] = EI,
    [0xFC] = CM, [0xFD] = CALL, [0xFE] = CPI, [0xFF] = RST_7
};

#endif
