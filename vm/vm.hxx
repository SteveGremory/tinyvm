#pragma once
#include <cinttypes>
#include <vector>

class VM {
public:
        /**
         * @brief Start the exection of the program
         * @param program The bytecode for the program to be run
         */
        VM(std::vector<uint32_t>& program);

        /**
         * @brief Execute the current instruction
         */
        void execute();

        /**
         * @brief Run the whole instruction set
         */
        void run();

private:
        // 256 Registers, 64 bit each
        int_fast64_t registers[256] = {0};

        // The program to be run
        std::vector<uint32_t> program;

        // 0 -> false
        // 1 -> true
        enum Instructions {
                // System Operations
                STALL,
                NONE,
                // Math
                ADD, // Add one register to another
                SUB, // Subtract one register from another
                MUL, // Multiplication
                DIV, // Division
                MOD, // Mod function
                INC, // Increment the reigster by 1
                NEG, // Decrement the register by 1
                // Branching
                JMP, // Unconditional Jump
                JNE, // Jump if both registers are NOT equal
                JE,  // Jump if both registers are equal
                // Memory Operations
                MOV, // Move
                TST, // Check if two registers are equal
                // Bitwise operations
                AND,
                OR,
                XOR,
                NOT,
                LSHIFT,
                RSHIFT,
                // TODO: Custom operations
                PRINT,
                POW,

        };
};
