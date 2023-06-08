#include <iostream>
#include <vm/vm.hxx>

/**
 * @brief Start the exection of the program
 */
VM::VM(std::vector<uint32_t>& program) : program(program) {

        this->running = true;
};

/**
 * @brief Decode the current instruction
 */
void decode() {}

#define set_regs(bytecode)                                                     \
        instruction = (*bytecode & 0xFF000000) >> 24;                          \
        reg1 = (*bytecode & 0xFF0000) >> 16;                                   \
        reg2 = (*bytecode & 0xFF00) >> 8;                                      \
        reg3 = (*bytecode & 0xFF);

/**
 * @brief Execute the current instruction
 */
void VM::execute() {

        static const void* jump_table[] = {
            &&do_STALL,  &&do_NONE,   &&do_ADD,  &&do_SUB, &&do_MUL, &&do_DIV,
            &&do_MOD,    &&do_INC,    &&do_NEG,  &&do_JMP, &&do_JNE, &&do_JE,
            &&do_MOV,    &&do_TST,    &&do_AND,  &&do_OR,  &&do_XOR, &&do_NOT,
            &&do_LSHIFT, &&do_RSHIFT, &&do_PRINT};

        auto data = this->program.data();
        uint32_t* bytecode = data;
        uint8_t instruction, reg1, reg2, reg3;
        set_regs(bytecode);
        goto* jump_table[instruction];

do_NONE : {
        bytecode++;

        set_regs(bytecode);
        goto* jump_table[instruction];
}

do_ADD : {
        registers[reg3] = registers[reg1] + registers[reg2];

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
do_SUB : {
        registers[reg3] = registers[reg1] - registers[reg2];

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
do_MUL : {
        registers[reg3] = registers[reg1] * registers[reg2];

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
do_DIV : {
        registers[reg3] = registers[reg1] / registers[reg2];

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
do_MOD : {
        registers[reg3] = registers[reg1] % registers[reg2];

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
do_INC : {
        registers[reg1]++;

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
do_NEG : {
        registers[reg1]++;

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
// Branching
do_JMP : {
        bytecode = data + reg1;

        set_regs(bytecode);
        goto* jump_table[instruction];
}
do_JNE : {
        if (registers[reg1] != registers[reg2]) {
                bytecode = data + reg3;
                set_regs(bytecode);
                goto* jump_table[instruction];
        }

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
do_JE : {
        if (registers[reg1] == registers[reg2]) {
                bytecode = data + reg3;
                set_regs(bytecode);
                goto* jump_table[instruction];
        }

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
// Memory Operations
do_MOV : {
        registers[reg1] = reg2;

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
do_TST : {
        registers[reg3] = registers[reg1] ^ registers[reg2];

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
// Bitwise operations
do_AND : {
        registers[reg3] = registers[reg1] & registers[reg2];

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
do_OR : {
        registers[reg3] = registers[reg1] | registers[reg2];

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
do_XOR : {
        registers[reg3] = registers[reg1] ^ registers[reg2];

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
do_NOT : {
        registers[reg2] = !(registers[reg1]);

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
do_LSHIFT : {
        registers[reg3] = registers[reg1] << registers[reg2];

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
do_RSHIFT : {
        registers[reg3] = registers[reg1] >> registers[reg2];

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
do_PRINT : {
        std::cout << reg1 << ": " << registers[reg1] << std::endl;

        bytecode++;
        set_regs(bytecode);
        goto* jump_table[instruction];
}
do_STALL : { return; }
}

/**
 * @brief Run the whole instruction set
 */
void VM::run() { this->execute(); }
