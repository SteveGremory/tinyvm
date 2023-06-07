#include "bytecodeio/bytecodeio.hxx"

ByteCodeIO::ByteCodeIO(std::filesystem::path& filepath) : filepath(filepath) {}

ByteCodeIO::ByteCodeIO(const char* filepath) {
        this->filepath = std::filesystem::path(filepath);
}

int ByteCodeIO::write(std::vector<uint32_t>& bytecode) {
        if (filepath.empty() || bytecode.empty()) {
                std::cerr << "No filepath or bytecode specified." << std::endl;
                return -1;
        }

        std::ofstream output(filepath, std::ios::binary);

        output << "TINYBITS";
        output << "--------";
        output << " UINT64 ";
        output << std::setfill('0') << std::setw(sizeof(uint32_t) * 2)
               << std::hex << bytecode.size();

        for (auto instruction : bytecode) {
                output << std::setfill('0') << std::setw(sizeof(uint32_t) * 2)
                       << std::hex << instruction;
        }

        output.close();

        return 0;
}

std::vector<uint32_t> ByteCodeIO::read() {
        auto stream = std::ifstream(filepath, std::ios::binary);
        std::vector<uint32_t> bytecode;

        stream.seekg(32);

        while (stream.peek() != EOF) {
                char temp[sizeof(uint32_t) * 2 + 1];
                stream.read(temp, sizeof(uint32_t) * 2);

                bytecode.push_back(strtol(temp, NULL, 16));
        }

        return bytecode;
}
