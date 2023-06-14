#include <exception>
#include <iostream>
#include <vm/vm.hxx>

/**
 * @brief Start the exection of the program
 */
VM::VM(std::vector<uint32_t>& program)
    : program(program) {};

#define set_regs(bytecode)                                                     \
        instruction = (*bytecode & 0xFF000000) >> 24;                          \
        if (instruction > jump_table_length) {                                 \
                std::cerr << "Invalid instruction: 0x" << std::hex             \
                          << *bytecode << std::endl;                           \
                exit(-1);                                                      \
        }                                                                      \
        reg1 = (*bytecode & 0xFF0000) >> 16;                                   \
        reg2 = (*bytecode & 0xFF00) >> 8;                                      \
        reg3 = (*bytecode & 0xFF);

#define next_instruction()                                                     \
        bytecode++;                                                            \
        set_regs(bytecode);                                                    \
        goto* jump_table[instruction];

#define jump_instruction(_data, _reg)                                          \
        bytecode = _data + _reg;                                               \
        set_regs(bytecode);                                                    \
        goto* jump_table[instruction];

/**
 * @brief Execute the current instruction
 */
void VM::run() {

        constexpr void* jump_table[] = {
            [STALL] = &&do_STALL,   [NONE] = &&do_NONE,
            [ADD] = &&do_ADD,       [SUB] = &&do_SUB,
            [MUL] = &&do_MUL,       [DIV] = &&do_DIV,
            [MOD] = &&do_MOD,       [INC] = &&do_INC,
            [NEG] = &&do_NEG,       [JMP] = &&do_JMP,
            [JNE] = &&do_JNE,       [JE] = &&do_JE,
            [MOV] = &&do_MOV,       [TST] = &&do_TST,
            [AND] = &&do_AND,       [OR] = &&do_OR,
            [XOR] = &&do_XOR,       [NOT] = &&do_NOT,
            [LSHIFT] = &&do_LSHIFT, [RSHIFT] = &&do_RSHIFT,
            [PRINT] = &&do_PRINT,
        };

        size_t jump_table_length = sizeof(jump_table) / sizeof(void*);

        auto data = this->program.data();

        uint32_t* bytecode = data;
        uint8_t instruction, reg1, reg2, reg3;

        set_regs(bytecode);
        goto* jump_table[instruction];

do_NONE : { next_instruction(); }

do_ADD : {
        registers[reg3] = registers[reg1] + registers[reg2];

        next_instruction();
}

do_SUB : {
        registers[reg3] = registers[reg1] - registers[reg2];

        next_instruction();
}

do_MUL : {
        registers[reg3] = registers[reg1] * registers[reg2];

        next_instruction();
}

do_DIV : {
        registers[reg3] = registers[reg1] / registers[reg2];

        next_instruction();
}

do_MOD : {
        registers[reg3] = registers[reg1] % registers[reg2];

        next_instruction();
}

do_INC : {
        registers[reg1]++;

        next_instruction();
}

do_NEG : {
        registers[reg1]--;

        next_instruction();
}

// Branching
do_JMP : { jump_instruction(data, reg1); }

do_JNE : {
        if (registers[reg1] != registers[reg2]) {
                jump_instruction(data, reg3);
        }
        next_instruction();
}

do_JE : {
        if (registers[reg1] == registers[reg2]) {
                jump_instruction(data, reg3);
        }

        next_instruction();
}

// Memory Operations
do_MOV : {
        registers[reg1] = reg2;

        next_instruction();
}

do_TST : {
        registers[reg3] = registers[reg1] ^ registers[reg2];

        next_instruction();
}

// Bitwise operations
do_AND : {
        registers[reg3] = registers[reg1] & registers[reg2];

        next_instruction();
}

do_OR : {
        registers[reg3] = registers[reg1] | registers[reg2];

        next_instruction();
}

do_XOR : {
        registers[reg3] = registers[reg1] ^ registers[reg2];

        next_instruction();
}

do_NOT : {
        registers[reg2] = !(registers[reg1]);

        next_instruction();
}

do_LSHIFT : {
        registers[reg3] = registers[reg1] << registers[reg2];

        next_instruction();
}

do_RSHIFT : {
        registers[reg3] = registers[reg1] >> registers[reg2];

        next_instruction();
}

do_PRINT : { std::cout << "Value: " << registers[reg1] << std::endl; }

do_STALL : { return; }
}
