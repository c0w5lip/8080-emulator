#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "../include/main.h"


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
    while (p->PC < 16) { // while (!pc->is_halted) eventually
        uint8_t opcode = p->memory[p->PC]; // fetch

        printf("Fetching %2x\n", opcode);

        if (!instructions[opcode]) {
            puts("Not supported!"); // all instructions must be supported eventually
            p->PC++;
            continue;
        }

        instructions[opcode](p); // execute
        p->cycle_count += cycles[opcode];
    }

    free(p->memory);
    free(p);
    
    return 0;
}
