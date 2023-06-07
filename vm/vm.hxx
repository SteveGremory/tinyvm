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
        int_fast64_t registers[256] = {0};

        // The program to be run
        std::vector<uint32_t> program;
        // Program counter
        uint_fast64_t program_counter;

        // State of the machine; false when halted
        bool running;

        // 0 -> false
        // 1 -> true
        enum Instructions {
                // Math
                NONE = 0x00,
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
                // TODO: Custom operations
                WRITEFILE_SYNC = 0x18,
                WRITEFILE_ASYNC = 0x19,
                SOCKET_OPEN = 0x2A,
                SOCKET_CONNECT = 0x2B,
                PRINT = 0x2C,
                // System Operations
                STALL = 0x69
        };
};
