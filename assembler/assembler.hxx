#pragma once

#include <filesystem>
#include <iostream>
#include <vector>

class Assembler {
public:
        /**
         * @brief Constructor: Reads the ASM code from the file and stores it in
         * a class variable
         * @param asm_file Path to the assembly file to be assembled to bytecode
         */
        Assembler(std::filesystem::path& asm_file);

        /**
         * @brief Constructor: Reads the ASM code from the file and stores it in
         * a class variable
         * @param asm_code The assembly code to be assembled to bytecode
         */
        Assembler(std::string& asm_code);

        /**
         * @brief destructor
         * @param asmfile The assembly file to be assembled to bytecode
         */
        ~Assembler() = default;

        /**
         * @brief Converts the assembly to the VM specific bytecode (assembles
         *        the code)
         * @returns bytecode for the asm program that was passed in as a
         * parameter
         */
        std::vector<uint32_t> assemble();

        /**
         * @brief Writes the bytecode to the specified
         *        file
         * @param outpath Path to the file where the bytecode should be written
         * @returns -1 if the process fails, 0 if the process succeeds
         */
        int write(std::filesystem::path& outpath);

private:
        std::string asm_code;
};
