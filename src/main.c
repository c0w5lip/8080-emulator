#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "../include/processor.h"


int main(int argc, char* argv[]) {
    
    if (argc != 2) {
        puts("Usage: ./emulator <program.rom>\n");
        return 1;
    }

    FILE *program_file = fopen(argv[1], "rb");

    if (!program_file) {
        perror("Couldn't open program");
        return 1;
    }

    fseek(program_file, 0L, SEEK_END);
    uint64_t program_file_size = ftell(program_file);
    fseek(program_file, 0L, SEEK_SET);



    Processor *p = calloc(1, sizeof(Processor));

    p->memory = malloc(0x10000);
    if (!p->memory) {
        perror("Couldn't allocate memory");
    }

    fread(p->memory, program_file_size, 1, program_file);
    fclose(program_file);

    p->PC = 0;
    while (!p->is_halted && p->PC < 1600) {
        unsigned char *opcode = &p->memory[p->PC]; // fetch
        unsigned char opcode_i = opcode[0];
        uint16_t PC_save = p->PC;

        printf("Fetching %2x\n", opcode_i);

        instructions[opcode_i](p, opcode); // execute
        
        if (p->PC == PC_save) { // if PC has been updated (e.g sucessful CNC), it must not be incremented
            p->PC += lengths[opcode_i]; // increment PC
        }
        
        p->cycle_count += cycles[opcode_i]; // increment cycle_counts
    }

    free(p->memory);
    free(p);
    
    return 0;
}
