#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "../include/main.h"


void NOP(Processor *p) {
    puts("NOP called");
    p->PC++;
}

void LXI_SP_d16(Processor *p) {
    puts("LXI_SP_d16 called");

    p->PC+=3;
}

void (*instructions[256])   (Processor*) = {
    NOP,
    [0x31] = LXI_SP_d16
};


int main(uint8_t argc, const char* argv[]) {
    
    if (argc != 2) {
        puts("Usage: ./emulator <program.rom>\n");
        return 1;
    }

    FILE *program_file = fopen(argv[1], "rb");

    if (!program_file) {
        perror("Couldn't open program");
        return 1;
    }

    fseek(program_file, 0, SEEK_END);
    uint64_t program_file_size = ftell(program_file);
    rewind(program_file);

    uint8_t *program_file_buffer = malloc(program_file_size);

    if (!program_file_buffer) {
        perror("Couldn't allocate buffer");
        fclose(program_file);
        return 1;
    }


    Processor *p = calloc(1, sizeof(Processor));

    p->memory = malloc(0x10000);
    fread(p->memory, program_file_size, 1, program_file);

    fclose(program_file);
    free(program_file_buffer);

    for (p->PC = 0; p->PC < 16;) {
        uint8_t opcode = p->memory[p->PC]; // fetch

        printf("Fetching %2x\n", opcode);

        if (!instructions[opcode]) {
            puts("Not supported!"); // all instructions have to be supported eventually
            p->PC++;
            continue;
        }

        instructions[opcode](p); // execute
    }

    free(p->memory);
    
    return 0;
}
