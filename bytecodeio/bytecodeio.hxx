#pragma once
#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

class ByteCodeIO {
public:
        /**
         * @brief Constructor for ByteCodeIO
         * @param filepath Path to the file that is to be operated on
         */
        ByteCodeIO(std::filesystem::path& filepath);

        /**
         * @brief Constructor for ByteCodeIO
         * @param filepath Path to the file that is to be operated on
         */
        ByteCodeIO(const char* filepath);

        ~ByteCodeIO() = default;

        /**
         * @brief Writes the bytecode to the file specified in the constructor
         * @param bytecode A reference to the vector containing the bytecode
         * @returns -1 If the process fails and 0 If the process succeeds
         */
        int write(std::vector<uint32_t>& bytecode);

        /**
         * @brief Reads the bytecode from the file specified in the constructor
         * @returns A std::vector<uint32_t> containing the bytecode
         */
        std::vector<uint32_t> read();

private:
        std::filesystem::path filepath;
};