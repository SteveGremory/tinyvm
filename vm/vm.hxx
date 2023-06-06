#pragma once
#include <cinttypes>

class VM {
public:
        /**
         * @brief Start the exection of the program
         */
        VM(uint64_t program[]);

        /**
         * @brief Decode the current instruction
         */
        void decode();

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
        int registers[256] = {0};

        // The program to be run
        uint64_t* program;
        // Program counter
        uint64_t program_counter;

        // State of the machine; false when halted
        bool running;

        // 0 -> false
        // 1 -> true
        enum Instructions {
                // Math
                ADD = 0x01, // Add one register to another
                SUB = 0x02, // Subtract one register from another
                MUL = 0x03, // Multiplication
                DIV = 0x04, // Division
                MOD = 0x05, // Mod function
                INC = 0x06, // Increment the reigster by 1
                NEG = 0x07, // Decrement the register by 1
                // Branching
                JMP = 0x0A, // Unconditional Jump
                JNE = 0x0B, // Jump if both registers are NOT equal
                JE = 0x0C,  // Jump if both registers are equal
                // Memory Operations
                MOV = 0x0D, // Move
                TST = 0x0E, // Check if two registers are equal
                // Bitwise operations
                AND = 0x12,
                OR = 0x13,
                XOR = 0x14,
                NOT = 0x15,
                LSHIFT = 0x16,
                RSHIFT = 0x17,
                // System Operations
                STALL = 0x69
                // TODO: Custom operations
        };
};
