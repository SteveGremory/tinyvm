#include <iostream>
#include <vm/vm.hxx>

/**
 * @brief Start the exection of the program
 */
VM::VM(uint64_t program[]) : program(program) {
        program_counter = 0;
        this->running = true;
};

/**
 * @brief Decode the current instruction
 */
void decode() {}

/**
 * @brief Execute the current instruction
 */
void VM::execute() {
        do {
                int bytecode = program[program_counter++];

                int instruction = (bytecode & 0xFF000000) >> 24;
                int reg1 = (bytecode & 0xFF0000) >> 16;
                int reg2 = (bytecode & 0xFF00) >> 8;
                int reg3 = (bytecode & 0xFF);

                // printf("Instr:%d\nReg1: %d\nReg2: %d\nReg3: %d\n",
                // instruction, reg1, reg2, reg3);

                switch (instruction) {
                case ADD:
                        registers[reg3] = registers[reg1] + registers[reg2];
                        std::cout << "Result: " << registers[reg3] << std::endl;
                        break;

                case SUB:
                case MUL:
                case DIV:
                case MOD:
                case INC:
                case NEG:
                // Branching
                case JMP:
                case JNE:
                case JE:
                        std::cerr << "Not implemented it yet." << std::endl;
                        break;
                // Memory Operations
                case MOV:
                        registers[reg1] = reg2;
                        break;
                case TST:
                        registers[reg3] = registers[reg1] ^ registers[reg2];
                        break;
                // Bitwise operations
                case AND:
                case OR:
                case XOR:
                case NOT:
                case LSHIFT:
                case RSHIFT:
                case STALL:
                        running = false;
                        break;
                default:
                        running = false;
                        break;
                }
        } while (this->running);
}

/**
 * @brief Run the whole instruction set
 */
void VM::run() { this->execute(); }