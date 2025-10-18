#include <stdio.h>

#include "../include/processor.h"


void NOP(Processor *p) {}


void MOV_B_B(Processor *p, unsigned char *opcode) { p->B = p->B; }
void MOV_B_C(Processor *p, unsigned char *opcode) { p->B = p->C; }
void MOV_B_D(Processor *p, unsigned char *opcode) { p->B = p->D; }
void MOV_B_E(Processor *p, unsigned char *opcode) { p->B = p->E; }
void MOV_B_H(Processor *p, unsigned char *opcode) { p->B = p->H; }
void MOV_B_L(Processor *p, unsigned char *opcode) { p->B = p->L; }
void MOV_B_M(Processor *p, unsigned char *opcode) { p->B = p->memory[(p->H << 8) | (p->L)]; }
void MOV_B_A(Processor *p, unsigned char *opcode) { p->B = p->A; }

void MOV_C_B(Processor *p, unsigned char *opcode) { p->C = p->B; }
void MOV_C_C(Processor *p, unsigned char *opcode) { p->C = p->C; }
void MOV_C_D(Processor *p, unsigned char *opcode) { p->C = p->D; }
void MOV_C_E(Processor *p, unsigned char *opcode) { p->C = p->E; }
void MOV_C_H(Processor *p, unsigned char *opcode) { p->C = p->H; }
void MOV_C_L(Processor *p, unsigned char *opcode) { p->C = p->L; }
void MOV_C_M(Processor *p, unsigned char *opcode) { p->C = p->memory[(p->H << 8) | (p->L)]; }
void MOV_C_A(Processor *p, unsigned char *opcode) { p->C = p->A; }

void MOV_D_B(Processor *p, unsigned char *opcode) { p->D = p->B; }
void MOV_D_C(Processor *p, unsigned char *opcode) { p->D = p->C; }
void MOV_D_D(Processor *p, unsigned char *opcode) { p->D = p->D; }
void MOV_D_E(Processor *p, unsigned char *opcode) { p->D = p->E; }
void MOV_D_H(Processor *p, unsigned char *opcode) { p->D = p->H; }
void MOV_D_L(Processor *p, unsigned char *opcode) { p->D = p->L; }
void MOV_D_M(Processor *p, unsigned char *opcode) { p->D = p->memory[(p->H << 8) | (p->L)]; }
void MOV_D_A(Processor *p, unsigned char *opcode) { p->D = p->A; }

void MOV_E_B(Processor *p, unsigned char *opcode) { p->E = p->B; }
void MOV_E_C(Processor *p, unsigned char *opcode) { p->E = p->C; }
void MOV_E_D(Processor *p, unsigned char *opcode) { p->E = p->D; }
void MOV_E_E(Processor *p, unsigned char *opcode) { p->E = p->E; }
void MOV_E_H(Processor *p, unsigned char *opcode) { p->E = p->H; }
void MOV_E_L(Processor *p, unsigned char *opcode) { p->E = p->L; }
void MOV_E_M(Processor *p, unsigned char *opcode) { p->E = p->memory[(p->H << 8) | (p->L)]; }
void MOV_E_A(Processor *p, unsigned char *opcode) { p->E = p->A; }

void MOV_H_B(Processor *p, unsigned char *opcode) { p->H = p->B; }
void MOV_H_C(Processor *p, unsigned char *opcode) { p->H = p->C; }
void MOV_H_D(Processor *p, unsigned char *opcode) { p->H = p->D; }
void MOV_H_E(Processor *p, unsigned char *opcode) { p->H = p->E; }
void MOV_H_H(Processor *p, unsigned char *opcode) { p->H = p->H; }
void MOV_H_L(Processor *p, unsigned char *opcode) { p->H = p->L; }
void MOV_H_M(Processor *p, unsigned char *opcode) { p->H = p->memory[(p->H << 8) | (p->L)]; }
void MOV_H_A(Processor *p, unsigned char *opcode) { p->H = p->A; }

void MOV_L_B(Processor *p, unsigned char *opcode) { p->L = p->B; }
void MOV_L_C(Processor *p, unsigned char *opcode) { p->L = p->C; }
void MOV_L_D(Processor *p, unsigned char *opcode) { p->L = p->D; }
void MOV_L_E(Processor *p, unsigned char *opcode) { p->L = p->E; }
void MOV_L_H(Processor *p, unsigned char *opcode) { p->L = p->H; }
void MOV_L_L(Processor *p, unsigned char *opcode) { p->L = p->L; }
void MOV_L_M(Processor *p, unsigned char *opcode) { p->L = p->memory[(p->H << 8) | (p->L)]; }
void MOV_L_A(Processor *p, unsigned char *opcode) { p->L = p->A; }

void MOV_M_B(Processor *p, unsigned char *opcode) { p->memory[(p->H << 8) | (p->L)] = p->B; }
void MOV_M_C(Processor *p, unsigned char *opcode) { p->memory[(p->H << 8) | (p->L)] = p->C; }
void MOV_M_D(Processor *p, unsigned char *opcode) { p->memory[(p->H << 8) | (p->L)] = p->D; }
void MOV_M_E(Processor *p, unsigned char *opcode) { p->memory[(p->H << 8) | (p->L)] = p->E; }
void MOV_M_H(Processor *p, unsigned char *opcode) { p->memory[(p->H << 8) | (p->L)] = p->H; }
void MOV_M_L(Processor *p, unsigned char *opcode) { p->memory[(p->H << 8) | (p->L)] = p->L; }
void HLT(Processor *p, unsigned char *opcode) { p->is_halted = true; }
void MOV_M_A(Processor *p, unsigned char *opcode) { p->memory[(p->H << 8) | (p->L)] = p->A; }

void MOV_A_B(Processor *p, unsigned char *opcode) { p->A = p->B; }
void MOV_A_C(Processor *p, unsigned char *opcode) { p->A = p->C; }
void MOV_A_D(Processor *p, unsigned char *opcode) { p->A = p->D; }
void MOV_A_E(Processor *p, unsigned char *opcode) { p->A = p->E; }
void MOV_A_H(Processor *p, unsigned char *opcode) { p->A = p->H; }
void MOV_A_L(Processor *p, unsigned char *opcode) { p->A = p->L; }
void MOV_A_M(Processor *p, unsigned char *opcode) { p->A = p->memory[(p->H << 8) | (p->L)]; }
void MOV_A_A(Processor *p, unsigned char *opcode) { p->A = p->A; }





void MVI_B(Processor *p, unsigned char *opcode) { p->B = opcode[1]; }
void MVI_C(Processor *p, unsigned char *opcode) { p->C = opcode[1]; }
void MVI_D(Processor *p, unsigned char *opcode) { p->D = opcode[1]; }
void MVI_E(Processor *p, unsigned char *opcode) { p->E = opcode[1]; }
void MVI_H(Processor *p, unsigned char *opcode) { p->H = opcode[1]; }
void MVI_L(Processor *p, unsigned char *opcode) { p->L = opcode[1]; }
void MVI_M(Processor *p, unsigned char *opcode) { p->memory[(p->H << 8) | (p->L)] = opcode[1]; }
void MVI_A(Processor *p, unsigned char *opcode) { p->A = opcode[1]; }

void LXI_B(Processor* p, unsigned char *opcode) { p->B = opcode[2]; p->C = opcode[1]; }
void LXI_D(Processor* p, unsigned char *opcode) { p->D = opcode[2]; p->E = opcode[1]; }
void LXI_H(Processor* p, unsigned char *opcode) { p->H = opcode[2]; p->L = opcode[1]; }
void LXI_SP(Processor* p, unsigned char *opcode) { p->SP = (opcode[2] << 8) | opcode[1]; }

void LDA(Processor *p, unsigned char *opcode) { p->A = p->memory[(opcode[2] << 8) | opcode[1]]; }
void STA(Processor *p, unsigned char *opcode) { p->memory[(opcode[2] << 8) | opcode[1]] = p->A; }

void LHLD(Processor *p, unsigned char *opcode) {
    uint16_t address = (opcode[2] << 8) | opcode[1];

    p->H = p->memory[address+1];
    p->L = p->memory[address];
}

void SHLD(Processor *p, unsigned char *opcode) {
    uint16_t address = (opcode[2] << 8) | opcode[1];

    p->memory[address+1] = p->H;
    p->memory[address] = p->L;
}


void XCHG(Processor *p, unsigned char *opcode) {
    uint8_t D_save = p->D;
    uint8_t E_save = p->E;

    p->D = p->H;
    p->E = p->L;

    p->H = D_save;
    p->L = E_save;
}

void LDAX_B(Processor *p, unsigned char *opcode) { p->A = p->memory[(p->B << 8) | p->C]; }
void LDAX_D(Processor *p, unsigned char *opcode) { p->A = p->memory[(p->D << 8) | p->E]; }

void STAX_B(Processor *p, unsigned char *opcode) { p->memory[(p->B << 8) | p->C] = p->A; }
void STAX_D(Processor *p, unsigned char *opcode) { p->memory[(p->D << 8) | p->E] = p->A; }


void INX_B(Processor *p, unsigned char *opcode) {
    if (++p->C == 0) {
        p->B++;
    }
}

void INX_D(Processor *p, unsigned char *opcode) {
    if (++p->E == 0) {
        p->D++;
    }
}

void INX_H(Processor *p, unsigned char *opcode) {
    if (++p->L == 0) {
        p->H++;
    }
}

void INX_SP(Processor *p, unsigned char *opcode) {
    p->SP++;
}




void DCX_B(Processor *p, unsigned char *opcode) {
    if (--p->C == 0xFF) {
        p->B--;
    }
}

void DCX_D(Processor *p, unsigned char *opcode) {
    if (--p->E == 0xFF) {
        p->D--;
    }
}

void DCX_H(Processor *p, unsigned char *opcode) {
    if (--p->L == 0xFF) {
        p->H--;
    }
}

void DCX_SP(Processor *p, unsigned char *opcode) {
    p->SP--;
}




void DAD_B(Processor* p, unsigned char *opcode) {
    uint32_t r = ((p->H  << 8) | p->L) + ((p->B << 8) | p->C);

    p->H = (r & 0xFF00) >> 8;
    p->L = (r & 0xFF);

    if (r > 0xFFFF) {
        p->F.C = 1;
    } else {
        p->F.C = 0;
    }
}

void DAD_D(Processor* p, unsigned char *opcode) {
    uint32_t r = ((p->H  << 8) | p->L) + ((p->D << 8) | p->E);

    p->H = (r & 0xFF00) >> 8;
    p->L = (r & 0xFF);

    if (r > 0xFFFF) {
        p->F.C = 1;
    } else {
        p->F.C = 0;
    }
}


void DAD_H(Processor* p, unsigned char *opcode) {
    uint32_t r = ((p->H << 8) | p->L) + ((p->H  << 8) | p->L); // = *2

    p->H = (r & 0xFF00) >> 8;
    p->L = (r & 0xFF);

    if (r > 0xFFFF) {
        p->F.C = 1;
    } else {
        p->F.C = 0;
    }
}


void DAD_SP(Processor* p, unsigned char *opcode) {
    uint32_t r = ((p->H  << 8) | p->L) + p->SP;

    p->H = (r & 0xFF00) >> 8;
    p->L = (r & 0xFF);

    if (r > 0xFFFF) {
        p->F.C = 1;
    } else {
        p->F.C = 0;
    }
}





void RLC(Processor *p, unsigned char *opcode) {
    uint8_t a = p->A;

    p->A = ((a & 0x80) >> 7) | (a << 1);
    p->F.C = ((a & 0x80) == 0x80);  
}

void RRC(Processor *p, unsigned char *opcode) {
    uint8_t a = p->A;

    p->A = ((a & 1) << 7) | (a >> 1);
    p->F.C = ((a & 1) == 1); 
}

void RAL(Processor *p, unsigned char *opcode) {
    uint8_t a = p->A;

    p->A = (a << 1) | (p->F.C & 0x1);
    p->F.C = ((a & 0x80) == 0x80);
}

void RAR(Processor *p, unsigned char *opcode) {
    uint8_t a = p->A;

    p->A = (p->F.C << 7) | (a >> 1);
    p->F.C = ((a & 1) == 1);
}






void ADI(Processor *p, unsigned char *opcode) {
    p->A += opcode[1];
}


void ACI(Processor *p, unsigned char *opcode) {
    uint16_t r = p->A + opcode[1] + p->F.C;

    p->A = r;

    set_flag_zsp(p, r);
    p->F.C = r > 0xFF;
    p->A = r & 0xFF;
}



void RNC(Processor *p, unsigned char *opcode) {
    if (p->F.C == 0) {
        RET(p, opcode);
    }
}


void RC(Processor *p, unsigned char *opcode) {
    if (p->F.C != 0) {
        RET(p, opcode);
    }
}









void CMA(Processor *p, unsigned char *opcode) {
    p->A = ~(p->A);
}


void CMC(Processor *p, unsigned char *opcode) {
    p->F.C = ~(p->F.C);
}




void STC(Processor *p, unsigned char *opcode) { p->F.C = 1; }
void STC(Processor *p, unsigned char *opcode) { p->F.C = 1; }



void JMP(Processor *p, unsigned char *opcode) {
    p->PC = p->memory[(opcode[2] << 8) | opcode[1]];
}

void JZ(Processor *p, unsigned char *opcode) {
    if (p->F.Z != 0) {
        JMP(p, opcode);
    }
}

void JNZ(Processor *p, unsigned char *opcode) {
    if (p->F.Z == 0) {
        JMP(p, opcode);
    }
}

void JC(Processor *p, unsigned char *opcode) {
    if (p->F.C != 0) {
        JMP(p, opcode);
    }
}

void JNC(Processor *p, unsigned char *opcode) {
    if (p->F.C == 0) {
        JMP(p, opcode);
    }
}

void JP(Processor *p, unsigned char *opcode) {
    if (p->F.S == 0) {
        JMP(p, opcode);
    }
}

void JPE(Processor *p, unsigned char *opcode) {
    if (p->F.P != 0) {
        JMP(p, opcode);
    }
}

void JPO(Processor *p, unsigned char *opcode) {
    if (p->F.P == 0) {
        JMP(p, opcode);
    }
}


void RET(Processor *p, unsigned char *opcode) {
    p->PC = (p->memory[p->SP]) | (p->memory[p->SP+1 << 8]);
}

void RZ(Processor *p, unsigned char *opcode) {
    if (p->F.Z != 0) {
        RET(p, opcode);
    }
}

void RNZ(Processor *p, unsigned char *opcode) {
    if (p->F.Z == 0) {
        RET(p, opcode);
    }
}




void CALL(Processor *p, unsigned char *opcode) {
    push(p->PC, 0, 0); // TODO: adapt push()
    JMP(p, opcode);
}


void CZ(Processor *p, unsigned char *opcode) {
    if (p->F.Z == 0) {
        CALL(p, opcode);
    }
}

void CNZ(Processor *p, unsigned char *opcode) {
    if (p->F.Z != 0) {
        CALL(p, opcode);
    }
}





void EI(Processor *p, unsigned char *opcode) {
    p->interrupts_enabled = true;
}

void DI(Processor *p, unsigned char *opcode) {
    p->interrupts_enabled = false;
}



void IN(Processor *p, unsigned char *opcode) {
    // TODO: ?
}

void OUT(Processor *p, unsigned char *opcode) {
    // TODO: print something?
}




void PCHL(Processor *p, unsigned char *opcode) {
    JMP(p, (p->H << 8) | p->L);
}

void XTHL(Processor *p, unsigned char *opcode) {
    uint8_t save_H = p->H;
    uint8_t save_L = p->L;

    p->H = p->memory[p->SP+1];
    p->L = p->memory[p->SP];

    p->memory[p->SP] = save_L;
    p->memory[p->SP+1] = save_H;
}


void SPHL(Processor *p, unsigned char *opcode) {
    p->SP = (p->H << 8) | p->L;
}





void DAA(Processor *p, unsigned char *opcode) {
    if ((p->A & 0xF) > 9) {
        p->A += 6;
    }
    
    if ((p->A & 0xF0) > 0x90) {
        uint16_t r = (uint16_t) p->A + 0x60;
        ArithFlagsA(p, r);
        p->A = r & 0xFF;
    }
}



// instructions affecting flags


void ADD_B(Processor *p, unsigned char *opcode) { add(p, p->B); }
void ADD_C(Processor *p, unsigned char *opcode) { add(p, p->C); }
void ADD_D(Processor *p, unsigned char *opcode) { add(p, p->D); }
void ADD_E(Processor *p, unsigned char *opcode) { add(p, p->E); }
void ADD_H(Processor *p, unsigned char *opcode) { add(p, p->H); }
void ADD_L(Processor *p, unsigned char *opcode) { add(p, p->L); }
void ADD_M(Processor *p, unsigned char *opcode) { add(p, p->memory[(p->H << 8) | (p->L)]); }
void ADD_A(Processor *p, unsigned char *opcode) { add(p, p->A); }



void ANA_B(Processor *p, unsigned char *opcode) { ana(p, p->B); }
void ANA_C(Processor *p, unsigned char *opcode) { ana(p, p->C); }
void ANA_D(Processor *p, unsigned char *opcode) { ana(p, p->D); }
void ANA_E(Processor *p, unsigned char *opcode) { ana(p, p->E); }
void ANA_H(Processor *p, unsigned char *opcode) { ana(p, p->H); }
void ANA_L(Processor *p, unsigned char *opcode) { ana(p, p->L); }
void ANA_M(Processor *p, unsigned char *opcode) { ana(p, p->memory[(p->H << 8) | (p->L)]); }
void ANA_A(Processor *p, unsigned char *opcode) { ana(p, p->A); }





void ADC_B(Processor *p, unsigned char *opcode) { adc(p, p->B); }
void ADC_C(Processor *p, unsigned char *opcode) { adc(p, p->C); }
void ADC_D(Processor *p, unsigned char *opcode) { adc(p, p->D); }
void ADC_E(Processor *p, unsigned char *opcode) { adc(p, p->E); }
void ADC_H(Processor *p, unsigned char *opcode) { adc(p, p->H); }
void ADC_L(Processor *p, unsigned char *opcode) { adc(p, p->L); }
void ADC_M(Processor *p, unsigned char *opcode) { adc(p, p->memory[(p->H << 8) | (p->L)]); }
void ADC_A(Processor *p, unsigned char *opcode) { adc(p, p->A); }


void SUB_B(Processor *p, unsigned char *opcode) { sub(p, p->B); }
void SUB_C(Processor *p, unsigned char *opcode) { sub(p, p->C); }
void SUB_D(Processor *p, unsigned char *opcode) { sub(p, p->D); }
void SUB_E(Processor *p, unsigned char *opcode) { sub(p, p->E); }
void SUB_H(Processor *p, unsigned char *opcode) { sub(p, p->H); }
void SUB_L(Processor *p, unsigned char *opcode) { sub(p, p->L); }
void SUB_M(Processor *p, unsigned char *opcode) { sub(p, p->memory[(p->H << 8) | (p->L)]); }
void SUB_A(Processor *p, unsigned char *opcode) { sub(p, p->A); }


void SBB_B(Processor *p, unsigned char *opcode) { sbb(p, p->B); }
void SBB_C(Processor *p, unsigned char *opcode) { sbb(p, p->C); }
void SBB_D(Processor *p, unsigned char *opcode) { sbb(p, p->D); }
void SBB_E(Processor *p, unsigned char *opcode) { sbb(p, p->E); }
void SBB_H(Processor *p, unsigned char *opcode) { sbb(p, p->H); }
void SBB_L(Processor *p, unsigned char *opcode) { sbb(p, p->L); }
void SBB_M(Processor *p, unsigned char *opcode) { sbb(p, p->memory[(p->H << 8) | (p->L)]); }
void SBB_A(Processor *p, unsigned char *opcode) { sbb(p, p->A); }



void INR_B(Processor *p, unsigned char *opcode) { inr(p, &p->B); }
void INR_C(Processor *p, unsigned char *opcode) { inr(p, &p->C); }
void INR_D(Processor *p, unsigned char *opcode) { inr(p, &p->D); }
void INR_E(Processor *p, unsigned char *opcode) { inr(p, &p->E); }
void INR_H(Processor *p, unsigned char *opcode) { inr(p, &p->H); }
void INR_L(Processor *p, unsigned char *opcode) { inr(p, &p->L); }
void INR_M(Processor *p, unsigned char *opcode) { inr(p, &p->memory[(p->H << 8) | (p->L)]); }
void INR_A(Processor *p, unsigned char *opcode) { inr(p, &p->A); }

void DCR_B(Processor *p, unsigned char *opcode) { dcr(p, &p->B); }
void DCR_C(Processor *p, unsigned char *opcode) { dcr(p, &p->C); }
void DCR_D(Processor *p, unsigned char *opcode) { dcr(p, &p->D); }
void DCR_E(Processor *p, unsigned char *opcode) { dcr(p, &p->E); }
void DCR_H(Processor *p, unsigned char *opcode) { dcr(p, &p->H); }
void DCR_L(Processor *p, unsigned char *opcode) { dcr(p, &p->L); }
void DCR_M(Processor *p, unsigned char *opcode) { dcr(p, &p->memory[(p->H << 8) | (p->L)]); }
void DCR_A(Processor *p, unsigned char *opcode) { dcr(p, &p->A); }


void XRA_B(Processor *p, unsigned char *opcode) { xra(p, &p->B); }
void XRA_C(Processor *p, unsigned char *opcode) { xra(p, &p->C); }
void XRA_D(Processor *p, unsigned char *opcode) { xra(p, &p->D); }
void XRA_E(Processor *p, unsigned char *opcode) { xra(p, &p->E); }
void XRA_H(Processor *p, unsigned char *opcode) { xra(p, &p->H); }
void XRA_L(Processor *p, unsigned char *opcode) { xra(p, &p->L); }
void XRA_M(Processor *p, unsigned char *opcode) { xra(p, &p->memory[(p->H << 8) | (p->L)]); }
void XRA_A(Processor *p, unsigned char *opcode) { xra(p, &p->A); }




void ORA_B(Processor *p, unsigned char *opcode) { ora(p, &p->B); }
void ORA_C(Processor *p, unsigned char *opcode) { ora(p, &p->C); }
void ORA_D(Processor *p, unsigned char *opcode) { ora(p, &p->D); }
void ORA_E(Processor *p, unsigned char *opcode) { ora(p, &p->E); }
void ORA_H(Processor *p, unsigned char *opcode) { ora(p, &p->H); }
void ORA_L(Processor *p, unsigned char *opcode) { ora(p, &p->L); }
void ORA_M(Processor *p, unsigned char *opcode) { ora(p, &p->memory[(p->H << 8) | (p->L)]); }
void ORA_A(Processor *p, unsigned char *opcode) { ora(p, &p->A); }



void CMP_B(Processor *p, unsigned char *opcode) { cmp(p, &p->B); }
void CMP_C(Processor *p, unsigned char *opcode) { cmp(p, &p->C); }
void CMP_D(Processor *p, unsigned char *opcode) { cmp(p, &p->D); }
void CMP_E(Processor *p, unsigned char *opcode) { cmp(p, &p->E); }
void CMP_H(Processor *p, unsigned char *opcode) { cmp(p, &p->H); }
void CMP_L(Processor *p, unsigned char *opcode) { cmp(p, &p->L); }
void CMP_M(Processor *p, unsigned char *opcode) { cmp(p, &p->memory[(p->H << 8) | (p->L)]); }
void CMP_A(Processor *p, unsigned char *opcode) { cmp(p, &p->A); }





void RST_0(Processor *p, unsigned char *opcode) { rst(p, 0*8); }
void RST_1(Processor *p, unsigned char *opcode) { rst(p, 1*8); }
void RST_2(Processor *p, unsigned char *opcode) { rst(p, 2*8); }
void RST_3(Processor *p, unsigned char *opcode) { rst(p, 3*8); }
void RST_4(Processor *p, unsigned char *opcode) { rst(p, 4*8); }
void RST_5(Processor *p, unsigned char *opcode) { rst(p, 5*8); }
void RST_6(Processor *p, unsigned char *opcode) { rst(p, 6*8); }
void RST_7(Processor *p, unsigned char *opcode) { rst(p, 7*8); }


void PUSH_B(Processor *p, unsigned char *opcode) { push(p, p->B, p->C); }
void PUSH_D(Processor *p, unsigned char *opcode) { push(p, p->D, p->E); }
void PUSH_H(Processor *p, unsigned char *opcode) { push(p, p->H, p->L); }
void PUSH_PSW(Processor *p, unsigned char *opcode) {
    push(p, p->A, (p->F.Z << 0 | p->F.S << 1 | p->F.P << 2 | p->F.C << 3 | p->F.A << 4));
}


void POP_B(Processor *p, unsigned char *opcode) { pop(p, &p->B, &p->C); }
void POP_D(Processor *p, unsigned char *opcode) { pop(p, &p->D, &p->E); }
void POP_H(Processor *p, unsigned char *opcode) { pop(p, &p->H, &p->L); }
void POP_PSW(Processor *p, unsigned char *opcode) { 
    p->A = p->memory[p->SP+1];
    p->F.Z = (0x01 == (p->memory[p->SP] & 0x01));
    p->F.S = (0x02 == (p->memory[p->SP] & 0x02));
    p->F.P = (0x04 == (p->memory[p->SP] & 0x04));
    p->F.C = (0x08 == (p->memory[p->SP] & 0x08));
    p->F.A = (0x10 == (p->memory[p->SP] & 0x10));

    p->SP += 2;
}




void CNC(Processor *p, unsigned char *opcode) {
    if (p->F.C == 0) {
        CALL(p, opcode);
        
        p->PC -= lengths[opcode[0]]; // cancel future incrementation of PC
    }
}



