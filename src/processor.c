#include "../include/processor.h"
#include "../include/wrappers.h"
#include "../include/helpers.h"


void NOP(Processor *p, unsigned char *opcode) {}


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
    uint16_t r = p->A + opcode[1];

    set_flag_zsp(p, r & 0xFF);
    p->F.C = (r > 0xFF);
    p->A = r & 0xFF;
}



void ANI(Processor *p, unsigned char *opcode) {
    p->A = p->A & opcode[1];

    update_flags_l(p);
}


void XRI(Processor *p, unsigned char *opcode) {
    uint8_t r = p->A ^ opcode[1];
    
    set_flag_zsp(p, r);
	p->F.C = 0;
	p->A = r;

    update_flags_l(p);
}


void ORI(Processor *p, unsigned char *opcode) {
    uint8_t a = p->A | opcode[1];

    set_flag_zsp(p, a);
    p->F.C = 0;
    p->A = a;

    update_flags_l(p);
}




void CPI(Processor *p, unsigned char *opcode) {

    uint8_t a = p->A - opcode[1];
    set_flag_zsp(p, a);
    p->F.C = (p->A < opcode[1]);
}




void SUI(Processor *p, unsigned char *opcode) {
    uint16_t r =  p->A - opcode[1];

    set_flag_zsp(p, r & 0xFF);
    p->F.C = (p->A < opcode[1]);
    p->A = r;
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
void JM(Processor *p, unsigned char *opcode) {
    if (p->F.S == 1) {
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
    p->SP += 2;
    p->PC = ((p->memory[p->SP + 1]) << 8) | (p->memory[p->SP]);
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




void RPO(Processor *p, unsigned char *opcode) {
    if (p->F.P == 0) {
        RET(p, opcode);
    }
}

void RPE(Processor *p, unsigned char *opcode) {
    if (p->F.P == 1) {
        RET(p, opcode);
    }
}

void CPO(Processor *p, unsigned char *opcode) {
    if (p->F.P == 0) {
        CALL(p, opcode);
    }
}

void CPE(Processor *p, unsigned char *opcode) {
    if (p->F.P == 1) {
        CALL(p, opcode);
    }
}



void RP(Processor *p, unsigned char *opcode) {
    if (p->F.S == 0) {
        RET(p, opcode);
    }
}


void CP(Processor *p, unsigned char *opcode) {
    if (p->F.S == 0) {
        CALL(p, opcode);
    }
}

void CM(Processor *p, unsigned char *opcode) {
    if (p->F.S == 1) {
        CALL(p, opcode);
    }
}



void RM(Processor *p, unsigned char *opcode) {
    if (p->F.S == 1) {
        RET(p, opcode);
    }
}



void CALL(Processor *p, unsigned char *opcode) {
    uint16_t ret_addr = p->PC + 3;
    push(p, (ret_addr >> 8) & 0xFF, ret_addr & 0xFF);
    p->PC = (opcode[2] << 8) | opcode[1];
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
    p->PC = (p->H << 8) | p->L; // JMP
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
        update_flags_a(p, r);
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


void SBI(Processor *p, unsigned char *opcode) {
    uint16_t r = p->A - opcode[1] - p->F.C;
    
    set_flag_zsp(p, r & 0xFF);
    p->F.C = (r > 0xFF);
    p->A = r & 0xFF;
}


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


void XRA_B(Processor *p, unsigned char *opcode) { xra(p, p->B); }
void XRA_C(Processor *p, unsigned char *opcode) { xra(p, p->C); }
void XRA_D(Processor *p, unsigned char *opcode) { xra(p, p->D); }
void XRA_E(Processor *p, unsigned char *opcode) { xra(p, p->E); }
void XRA_H(Processor *p, unsigned char *opcode) { xra(p, p->H); }
void XRA_L(Processor *p, unsigned char *opcode) { xra(p, p->L); }
void XRA_M(Processor *p, unsigned char *opcode) { xra(p, p->memory[(p->H << 8) | (p->L)]); }
void XRA_A(Processor *p, unsigned char *opcode) { xra(p, p->A); }




void ORA_B(Processor *p, unsigned char *opcode) { ora(p, p->B); }
void ORA_C(Processor *p, unsigned char *opcode) { ora(p, p->C); }
void ORA_D(Processor *p, unsigned char *opcode) { ora(p, p->D); }
void ORA_E(Processor *p, unsigned char *opcode) { ora(p, p->E); }
void ORA_H(Processor *p, unsigned char *opcode) { ora(p, p->H); }
void ORA_L(Processor *p, unsigned char *opcode) { ora(p, p->L); }
void ORA_M(Processor *p, unsigned char *opcode) { ora(p, p->memory[(p->H << 8) | (p->L)]); }
void ORA_A(Processor *p, unsigned char *opcode) { ora(p, p->A); }



void CMP_B(Processor *p, unsigned char *opcode) { cmp(p, p->B); }
void CMP_C(Processor *p, unsigned char *opcode) { cmp(p, p->C); }
void CMP_D(Processor *p, unsigned char *opcode) { cmp(p, p->D); }
void CMP_E(Processor *p, unsigned char *opcode) { cmp(p, p->E); }
void CMP_H(Processor *p, unsigned char *opcode) { cmp(p, p->H); }
void CMP_L(Processor *p, unsigned char *opcode) { cmp(p, p->L); }
void CMP_M(Processor *p, unsigned char *opcode) { cmp(p, p->memory[(p->H << 8) | (p->L)]); }
void CMP_A(Processor *p, unsigned char *opcode) { cmp(p, p->A); }





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




void CC(Processor *p, unsigned char *opcode) {
    if (p->F.C == 1) {
        CALL(p, opcode);
    }
}

void CNC(Processor *p, unsigned char *opcode) {
    if (p->F.C == 0) {
        CALL(p, opcode);
    }
}




























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



void (*instructions[256])(Processor*, unsigned char *opcode) = {
    [0x00] = NOP, [0x01] = LXI_B, [0x02] = STAX_B, [0x03] = INX_B,
    [0x04] = INR_B, [0x05] = DCR_B, [0x06] = MVI_B, [0x07] = RLC,
    [0x08] = NOP, [0x09] = DAD_B, [0x0A] = LDAX_B, [0x0B] = DCX_B,
    [0x0C] = INR_C, [0x0D] = DCR_C, [0x0E] = MVI_C, [0x0F] = RRC,

    [0x10] = NOP, [0x11] = LXI_D, [0x12] = STAX_D, [0x13] = INX_D,
    [0x14] = INR_D, [0x15] = DCR_D, [0x16] = MVI_D, [0x17] = RAL,
    [0x18] = NOP, [0x19] = DAD_D, [0x1A] = LDAX_D, [0x1B] = DCX_D,
    [0x1C] = INR_E, [0x1D] = DCR_E, [0x1E] = MVI_E, [0x1F] = RAR,

    [0x20] = NOP, [0x21] = LXI_H, [0x22] = SHLD, [0x23] = INX_H,
    [0x24] = INR_H, [0x25] = DCR_H, [0x26] = MVI_H, [0x27] = DAA,
    [0x28] = NOP, [0x29] = DAD_H, [0x2A] = LHLD, [0x2B] = DCX_H,
    [0x2C] = INR_L, [0x2D] = DCR_L, [0x2E] = MVI_L, [0x2F] = CMA,

    [0x30] = NOP, [0x31] = LXI_SP, [0x32] = STA, [0x33] = INX_SP,
    [0x34] = INR_M, [0x35] = DCR_M, [0x36] = MVI_M, [0x37] = STC,
    [0x38] = NOP, [0x39] = DAD_SP, [0x3A] = LDA, [0x3B] = DCX_SP,
    [0x3C] = INR_A, [0x3D] = DCR_A, [0x3E] = MVI_A, [0x3F] = CMC,

    [0x40] = MOV_B_B, [0x41] = MOV_B_C, [0x42] = MOV_B_D, [0x43] = MOV_B_E,
    [0x44] = MOV_B_H, [0x45] = MOV_B_L, [0x46] = MOV_B_M, [0x47] = MOV_B_A,
    [0x48] = MOV_C_B, [0x49] = MOV_C_C, [0x4A] = MOV_C_D, [0x4B] = MOV_C_E,
    [0x4C] = MOV_C_H, [0x4D] = MOV_C_L, [0x4E] = MOV_C_M, [0x4F] = MOV_C_A,

    [0x50] = MOV_D_B, [0x51] = MOV_D_C, [0x52] = MOV_D_D, [0x53] = MOV_D_E,
    [0x54] = MOV_D_H, [0x55] = MOV_D_L, [0x56] = MOV_D_M, [0x57] = MOV_D_A,
    [0x58] = MOV_E_B, [0x59] = MOV_E_C, [0x5A] = MOV_E_D, [0x5B] = MOV_E_E,
    [0x5C] = MOV_E_H, [0x5D] = MOV_E_L, [0x5E] = MOV_E_M, [0x5F] = MOV_E_A,

    [0x60] = MOV_H_B, [0x61] = MOV_H_C, [0x62] = MOV_H_D, [0x63] = MOV_H_E,
    [0x64] = MOV_H_H, [0x65] = MOV_H_L, [0x66] = MOV_H_M, [0x67] = MOV_H_A,
    [0x68] = MOV_L_B, [0x69] = MOV_L_C, [0x6A] = MOV_L_D, [0x6B] = MOV_L_E,
    [0x6C] = MOV_L_H, [0x6D] = MOV_L_L, [0x6E] = MOV_L_M, [0x6F] = MOV_L_A,

    [0x70] = MOV_M_B, [0x71] = MOV_M_C, [0x72] = MOV_M_D, [0x73] = MOV_M_E,
    [0x74] = MOV_M_H, [0x75] = MOV_M_L, [0x76] = HLT, [0x77] = MOV_M_A,
    [0x78] = MOV_A_B, [0x79] = MOV_A_C, [0x7A] = MOV_A_D, [0x7B] = MOV_A_E,
    [0x7C] = MOV_A_H, [0x7D] = MOV_A_L, [0x7E] = MOV_A_M, [0x7F] = MOV_A_A,

    [0x80] = ADD_B, [0x81] = ADD_C, [0x82] = ADD_D, [0x83] = ADD_E,
    [0x84] = ADD_H, [0x85] = ADD_L, [0x86] = ADD_M, [0x87] = ADD_A,
    [0x88] = ADC_B, [0x89] = ADC_C, [0x8A] = ADC_D, [0x8B] = ADC_E,
    [0x8C] = ADC_H, [0x8D] = ADC_L, [0x8E] = ADC_M, [0x8F] = ADC_A,

    [0x90] = SUB_B, [0x91] = SUB_C, [0x92] = SUB_D, [0x93] = SUB_E,
    [0x94] = SUB_H, [0x95] = SUB_L, [0x96] = SUB_M, [0x97] = SUB_A,
    [0x98] = SBB_B, [0x99] = SBB_C, [0x9A] = SBB_D, [0x9B] = SBB_E,
    [0x9C] = SBB_H, [0x9D] = SBB_L, [0x9E] = SBB_M, [0x9F] = SBB_A,

    [0xA0] = ANA_B, [0xA1] = ANA_C, [0xA2] = ANA_D, [0xA3] = ANA_E,
    [0xA4] = ANA_H, [0xA5] = ANA_L, [0xA6] = ANA_M, [0xA7] = ANA_A,
    [0xA8] = XRA_B, [0xA9] = XRA_C, [0xAA] = XRA_D, [0xAB] = XRA_E,
    [0xAC] = XRA_H, [0xAD] = XRA_L, [0xAE] = XRA_M, [0xAF] = XRA_A,

    [0xB0] = ORA_B, [0xB1] = ORA_C, [0xB2] = ORA_D, [0xB3] = ORA_E,
    [0xB4] = ORA_H, [0xB5] = ORA_L, [0xB6] = ORA_M, [0xB7] = ORA_A,
    [0xB8] = CMP_B, [0xB9] = CMP_C, [0xBA] = CMP_D, [0xBB] = CMP_E,
    [0xBC] = CMP_H, [0xBD] = CMP_L, [0xBE] = CMP_M, [0xBF] = CMP_A,

    [0xC0] = RNZ, [0xC1] = POP_B, [0xC2] = JNZ, [0xC3] = JMP,
    [0xC4] = CNZ, [0xC5] = PUSH_B, [0xC6] = ADI, [0xC7] = RST_0,
    [0xC8] = RZ, [0xC9] = RET, [0xCA] = JZ, [0xCB] = JMP,
    [0xCC] = CZ, [0xCD] = CALL, [0xCE] = ACI, [0xCF] = RST_1,

    [0xD0] = RNC, [0xD1] = POP_D, [0xD2] = JNC, [0xD3] = OUT,
    [0xD4] = CNC, [0xD5] = PUSH_D, [0xD6] = SUI, [0xD7] = RST_2,
    [0xD8] = RC, [0xD9] = RET, [0xDA] = JC, [0xDB] = IN,
    [0xDC] = CC, [0xDD] = CALL, [0xDE] = SBI, [0xDF] = RST_3,

    [0xE0] = RPO, [0xE1] = POP_H, [0xE2] = JPO, [0xE3] = XTHL,
    [0xE4] = CPO, [0xE5] = PUSH_H, [0xE6] = ANI, [0xE7] = RST_4,
    [0xE8] = RPE, [0xE9] = PCHL, [0xEA] = JPE, [0xEB] = XCHG,
    [0xEC] = CPE, [0xED] = CALL, [0xEE] = XRI, [0xEF] = RST_5,

    [0xF0] = RP, [0xF1] = POP_PSW, [0xF2] = JP, [0xF3] = DI,
    [0xF4] = CP, [0xF5] = PUSH_PSW, [0xF6] = ORI, [0xF7] = RST_6,
    [0xF8] = RM, [0xF9] = SPHL, [0xFA] = JM, [0xFB] = EI,
    [0xFC] = CM, [0xFD] = CALL, [0xFE] = CPI, [0xFF] = RST_7
};








