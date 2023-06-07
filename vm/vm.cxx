#include <iostream>
#include <vm/vm.hxx>

/**
 * @brief Start the exection of the program
 */
VM::VM(std::vector<uint32_t>& program) : program(program) {
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

        while (this->running) {
                int_fast32_t bytecode = program[program_counter++];

                int_fast8_t instruction = (bytecode & 0xFF000000) >> 24;
                int_fast32_t reg1 = (bytecode & 0xFF0000) >> 16;
                int_fast32_t reg2 = (bytecode & 0xFF00) >> 8;
                int_fast32_t reg3 = (bytecode & 0xFF);
                // printf("Instr:%d\nReg1: %d\nReg2: %d\nReg3: %d\n",
                // instruction, reg1, reg2, reg3);

                switch (instruction) {
                case ADD:
                        registers[reg3] = registers[reg1] + registers[reg2];
                        break;
                case SUB:
                        registers[reg3] = registers[reg1] - registers[reg2];
                        break;
                case MUL:
                        registers[reg3] = registers[reg1] * registers[reg2];

                        break;
                case DIV:
                        registers[reg3] = registers[reg1] / registers[reg2];
                        break;
                case MOD:
                        registers[reg3] = registers[reg1] % registers[reg2];
                        break;
                case INC:
                        registers[reg1]++;
                        break;
                case NEG:
                        registers[reg1]--;
                        break;
                // Branching
                case JMP:
                        program_counter = reg1;
                        break;
                case JNE:
                        if (registers[reg1] != registers[reg2]) {
                                program_counter = reg3;
                        }
                        break;
                case JE:
                        if (registers[reg1] == registers[reg2]) {
                                program_counter = reg3;
                        }
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
                        registers[reg3] = registers[reg1] & registers[reg2];
                        break;
                case OR:
                        registers[reg3] = registers[reg1] | registers[reg2];
                        break;
                case XOR:
                        registers[reg3] = registers[reg1] ^ registers[reg2];
                        break;
                case NOT:
                        registers[reg2] = !(registers[reg1]);
                        break;
                case LSHIFT:
                        registers[reg3] = registers[reg1] << registers[reg2];
                        break;
                case RSHIFT:
                        registers[reg3] = registers[reg1] >> registers[reg2];
                        break;
                case PRINT:
                        std::cout << reg1 << ": " << registers[reg1]
                                  << std::endl;
                        break;
                case STALL:
                        running = false;
                        break;
                default:
                        std::cerr << "This instruction hasn't been implemented!"
                                  << std::endl;
                        break;
                }
        }
}

/**
 * @brief Run the whole instruction set
 */
void VM::run() { this->execute(); }