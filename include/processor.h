#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <stdint.h>
#include <stdbool.h>

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

extern const uint8_t lengths[256];
extern const uint8_t cycles[256];
extern void (*instructions[256])(Processor*, unsigned char *opcode);

void STAX_B(Processor *p, unsigned char *opcode);
void STAX_D(Processor *p, unsigned char *opcode);
void NOP(Processor *p, unsigned char *opcode);
void EI(Processor *p, unsigned char *opcode);
void XCHG(Processor *p, unsigned char *opcode);
void SUI(Processor *p, unsigned char *opcode);
void ORI(Processor *p, unsigned char *opcode);
void ANI(Processor *p, unsigned char *opcode);
void ADI(Processor *p, unsigned char *opcode);
void OUT(Processor *p, unsigned char *opcode);
void CALL(Processor *p, unsigned char *opcode);
void JMP(Processor *p, unsigned char *opcode);
void RET(Processor *p, unsigned char *opcode);

void PUSH_PSW(Processor *p, unsigned char *opcode);
void PUSH_H(Processor *p, unsigned char *opcode);
void PUSH_D(Processor *p, unsigned char *opcode);
void PUSH_B(Processor *p, unsigned char *opcode);

void JNZ(Processor *p, unsigned char *opcode);
void JNC(Processor *p, unsigned char *opcode);
void JPO(Processor *p, unsigned char *opcode);
void JP(Processor *p, unsigned char *opcode);

void POP_PSW(Processor *p, unsigned char *opcode);
void POP_H(Processor *p, unsigned char *opcode);
void POP_D(Processor *p, unsigned char *opcode);
void POP_B(Processor *p, unsigned char *opcode);

void XRA_A(Processor *p, unsigned char *opcode);
void XRA_B(Processor *p, unsigned char *opcode);
void XRA_C(Processor *p, unsigned char *opcode);
void XRA_D(Processor *p, unsigned char *opcode);
void XRA_E(Processor *p, unsigned char *opcode);
void XRA_H(Processor *p, unsigned char *opcode);
void XRA_L(Processor *p, unsigned char *opcode);
void XRA_M(Processor *p, unsigned char *opcode);

void ANA_A(Processor *p, unsigned char *opcode);
void ANA_B(Processor *p, unsigned char *opcode);
void ANA_C(Processor *p, unsigned char *opcode);
void ANA_D(Processor *p, unsigned char *opcode);
void ANA_E(Processor *p, unsigned char *opcode);
void ANA_H(Processor *p, unsigned char *opcode);
void ANA_L(Processor *p, unsigned char *opcode);
void ANA_M(Processor *p, unsigned char *opcode);
void LDA(Processor *p, unsigned char *opcode);
void STA(Processor *p, unsigned char *opcode);
void LDAX_B(Processor *p, unsigned char *opcode);
void LDAX_D(Processor *p, unsigned char *opcode);
void INX_B(Processor *p, unsigned char *opcode);
void INX_H(Processor *p, unsigned char *opcode);
void INX_D(Processor *p, unsigned char *opcode);
void INX_SP(Processor *p, unsigned char *opcode);
void RRC(Processor *p, unsigned char *opcode);
void RLC(Processor *p, unsigned char *opcode);
void RAL(Processor *p, unsigned char *opcode);
void RAR(Processor *p, unsigned char *opcode);
void DAA(Processor *p, unsigned char *opcode);
void CMA(Processor *p, unsigned char *opcode);
void STC(Processor *p, unsigned char *opcode);
void CMC(Processor *p, unsigned char *opcode);

void DAD_H(Processor *p, unsigned char *opcode);
void DAD_D(Processor *p, unsigned char *opcode);
void DAD_B(Processor *p, unsigned char *opcode);
void DAD_SP(Processor *p, unsigned char *opcode);

void MVI_A(Processor *p, unsigned char *opcode);
void MVI_B(Processor *p, unsigned char *opcode);
void MVI_C(Processor *p, unsigned char *opcode);
void MVI_D(Processor *p, unsigned char *opcode);
void MVI_E(Processor *p, unsigned char *opcode);
void MVI_H(Processor *p, unsigned char *opcode);
void MVI_L(Processor *p, unsigned char *opcode);
void MVI_M(Processor *p, unsigned char *opcode);

void LXI_SP(Processor *p, unsigned char *opcode);
void LXI_H(Processor *p, unsigned char *opcode);
void LXI_D(Processor *p, unsigned char *opcode);
void LXI_B(Processor *p, unsigned char *opcode);

void MOV_A_A(Processor *p, unsigned char *opcode);
void MOV_A_B(Processor *p, unsigned char *opcode);
void MOV_A_C(Processor *p, unsigned char *opcode);
void MOV_A_D(Processor *p, unsigned char *opcode);
void MOV_A_E(Processor *p, unsigned char *opcode);
void MOV_A_H(Processor *p, unsigned char *opcode);
void MOV_A_L(Processor *p, unsigned char *opcode);
void MOV_A_M(Processor *p, unsigned char *opcode);

void MOV_B_A(Processor *p, unsigned char *opcode);
void MOV_B_B(Processor *p, unsigned char *opcode);
void MOV_B_C(Processor *p, unsigned char *opcode);
void MOV_B_D(Processor *p, unsigned char *opcode);
void MOV_B_E(Processor *p, unsigned char *opcode);
void MOV_B_H(Processor *p, unsigned char *opcode);
void MOV_B_L(Processor *p, unsigned char *opcode);
void MOV_B_M(Processor *p, unsigned char *opcode);

void MOV_C_A(Processor *p, unsigned char *opcode);
void MOV_C_B(Processor *p, unsigned char *opcode);
void MOV_C_C(Processor *p, unsigned char *opcode);
void MOV_C_D(Processor *p, unsigned char *opcode);
void MOV_C_E(Processor *p, unsigned char *opcode);
void MOV_C_H(Processor *p, unsigned char *opcode);
void MOV_C_L(Processor *p, unsigned char *opcode);
void MOV_C_M(Processor *p, unsigned char *opcode);

void MOV_D_A(Processor *p, unsigned char *opcode);
void MOV_D_B(Processor *p, unsigned char *opcode);
void MOV_D_C(Processor *p, unsigned char *opcode);
void MOV_D_D(Processor *p, unsigned char *opcode);
void MOV_D_E(Processor *p, unsigned char *opcode);
void MOV_D_H(Processor *p, unsigned char *opcode);
void MOV_D_L(Processor *p, unsigned char *opcode);
void MOV_D_M(Processor *p, unsigned char *opcode);

void MOV_E_A(Processor *p, unsigned char *opcode);
void MOV_E_B(Processor *p, unsigned char *opcode);
void MOV_E_C(Processor *p, unsigned char *opcode);
void MOV_E_D(Processor *p, unsigned char *opcode);
void MOV_E_E(Processor *p, unsigned char *opcode);
void MOV_E_H(Processor *p, unsigned char *opcode);
void MOV_E_L(Processor *p, unsigned char *opcode);
void MOV_E_M(Processor *p, unsigned char *opcode);

void MOV_H_A(Processor *p, unsigned char *opcode);
void MOV_H_B(Processor *p, unsigned char *opcode);
void MOV_H_C(Processor *p, unsigned char *opcode);
void MOV_H_D(Processor *p, unsigned char *opcode);
void MOV_H_E(Processor *p, unsigned char *opcode);
void MOV_H_H(Processor *p, unsigned char *opcode);
void MOV_H_L(Processor *p, unsigned char *opcode);
void MOV_H_M(Processor *p, unsigned char *opcode);

void MOV_L_A(Processor *p, unsigned char *opcode);
void MOV_L_B(Processor *p, unsigned char *opcode);
void MOV_L_C(Processor *p, unsigned char *opcode);
void MOV_L_D(Processor *p, unsigned char *opcode);
void MOV_L_E(Processor *p, unsigned char *opcode);
void MOV_L_H(Processor *p, unsigned char *opcode);
void MOV_L_L(Processor *p, unsigned char *opcode);
void MOV_L_M(Processor *p, unsigned char *opcode);

void MOV_M_A(Processor *p, unsigned char *opcode);
void MOV_M_B(Processor *p, unsigned char *opcode);
void MOV_M_C(Processor *p, unsigned char *opcode);
void MOV_M_D(Processor *p, unsigned char *opcode);
void MOV_M_E(Processor *p, unsigned char *opcode);
void MOV_M_H(Processor *p, unsigned char *opcode);
void MOV_M_L(Processor *p, unsigned char *opcode);

void HLT(Processor *p, unsigned char *opcode);

void ADD_A(Processor *p, unsigned char *opcode);
void ADD_B(Processor *p, unsigned char *opcode);
void ADD_C(Processor *p, unsigned char *opcode);
void ADD_D(Processor *p, unsigned char *opcode);
void ADD_E(Processor *p, unsigned char *opcode);
void ADD_H(Processor *p, unsigned char *opcode);
void ADD_L(Processor *p, unsigned char *opcode);
void ADD_M(Processor *p, unsigned char *opcode);

void ADC_A(Processor *p, unsigned char *opcode);
void ADC_B(Processor *p, unsigned char *opcode);
void ADC_C(Processor *p, unsigned char *opcode);
void ADC_D(Processor *p, unsigned char *opcode);
void ADC_E(Processor *p, unsigned char *opcode);
void ADC_H(Processor *p, unsigned char *opcode);
void ADC_L(Processor *p, unsigned char *opcode);
void ADC_M(Processor *p, unsigned char *opcode);

void SUB_A(Processor *p, unsigned char *opcode);
void SUB_B(Processor *p, unsigned char *opcode);
void SUB_C(Processor *p, unsigned char *opcode);
void SUB_D(Processor *p, unsigned char *opcode);
void SUB_E(Processor *p, unsigned char *opcode);
void SUB_H(Processor *p, unsigned char *opcode);
void SUB_L(Processor *p, unsigned char *opcode);
void SUB_M(Processor *p, unsigned char *opcode);

void SBB_A(Processor *p, unsigned char *opcode);
void SBB_B(Processor *p, unsigned char *opcode);
void SBB_C(Processor *p, unsigned char *opcode);
void SBB_D(Processor *p, unsigned char *opcode);
void SBB_E(Processor *p, unsigned char *opcode);
void SBB_H(Processor *p, unsigned char *opcode);
void SBB_L(Processor *p, unsigned char *opcode);
void SBB_M(Processor *p, unsigned char *opcode);

void ORA_A(Processor *p, unsigned char *opcode);
void ORA_B(Processor *p, unsigned char *opcode);
void ORA_C(Processor *p, unsigned char *opcode);
void ORA_D(Processor *p, unsigned char *opcode);
void ORA_E(Processor *p, unsigned char *opcode);
void ORA_H(Processor *p, unsigned char *opcode);
void ORA_L(Processor *p, unsigned char *opcode);
void ORA_M(Processor *p, unsigned char *opcode);

void CMP_A(Processor *p, unsigned char *opcode);
void CMP_B(Processor *p, unsigned char *opcode);
void CMP_C(Processor *p, unsigned char *opcode);
void CMP_D(Processor *p, unsigned char *opcode);
void CMP_E(Processor *p, unsigned char *opcode);
void CMP_H(Processor *p, unsigned char *opcode);
void CMP_L(Processor *p, unsigned char *opcode);
void CMP_M(Processor *p, unsigned char *opcode);

void INR_A(Processor *p, unsigned char *opcode);
void INR_B(Processor *p, unsigned char *opcode);
void INR_C(Processor *p, unsigned char *opcode);
void INR_D(Processor *p, unsigned char *opcode);
void INR_E(Processor *p, unsigned char *opcode);
void INR_H(Processor *p, unsigned char *opcode);
void INR_L(Processor *p, unsigned char *opcode);
void INR_M(Processor *p, unsigned char *opcode);

void DCR_A(Processor *p, unsigned char *opcode);
void DCR_B(Processor *p, unsigned char *opcode);
void DCR_C(Processor *p, unsigned char *opcode);
void DCR_D(Processor *p, unsigned char *opcode);
void DCR_E(Processor *p, unsigned char *opcode);
void DCR_H(Processor *p, unsigned char *opcode);
void DCR_L(Processor *p, unsigned char *opcode);
void DCR_M(Processor *p, unsigned char *opcode);

void DCX_B(Processor *p, unsigned char *opcode);
void DCX_D(Processor *p, unsigned char *opcode);
void DCX_H(Processor *p, unsigned char *opcode);
void DCX_SP(Processor *p, unsigned char *opcode);

void SHLD(Processor *p, unsigned char *opcode);
void LHLD(Processor *p, unsigned char *opcode);
void RNZ(Processor *p, unsigned char *opcode);
void RNC(Processor *p, unsigned char *opcode);
void RPO(Processor *p, unsigned char *opcode);
void RP(Processor *p, unsigned char *opcode);
void XTHL(Processor *p, unsigned char *opcode);
void DI(Processor *p, unsigned char *opcode);
void CNZ(Processor *p, unsigned char *opcode);
void CNC(Processor *p, unsigned char *opcode);
void CPO(Processor *p, unsigned char *opcode);
void CP(Processor *p, unsigned char *opcode);

void RST_0(Processor *p, unsigned char *opcode);
void RST_1(Processor *p, unsigned char *opcode);
void RST_2(Processor *p, unsigned char *opcode);
void RST_3(Processor *p, unsigned char *opcode);
void RST_4(Processor *p, unsigned char *opcode);
void RST_5(Processor *p, unsigned char *opcode);
void RST_6(Processor *p, unsigned char *opcode);
void RST_7(Processor *p, unsigned char *opcode);

void RZ(Processor *p, unsigned char *opcode);
void RC(Processor *p, unsigned char *opcode);
void RPE(Processor *p, unsigned char *opcode);
void RM(Processor *p, unsigned char *opcode);
void PCHL(Processor *p, unsigned char *opcode);
void SPHL(Processor *p, unsigned char *opcode);
void JC(Processor *p, unsigned char *opcode);
void JZ(Processor *p, unsigned char *opcode);
void JPE(Processor *p, unsigned char *opcode);
void JM(Processor *p, unsigned char *opcode);
void IN(Processor *p, unsigned char *opcode);
void CZ(Processor *p, unsigned char *opcode);
void CC(Processor *p, unsigned char *opcode);
void CPE(Processor *p, unsigned char *opcode);
void CM(Processor *p, unsigned char *opcode);
void ACI(Processor *p, unsigned char *opcode);
void SBI(Processor *p, unsigned char *opcode);
void XRI(Processor *p, unsigned char *opcode);
void CPI(Processor *p, unsigned char *opcode);


#endif
