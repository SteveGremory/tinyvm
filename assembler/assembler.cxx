#include <assembler/assembler.hxx>
#include <bytecodeio/bytecodeio.hxx>

Assembler::Assembler(std::filesystem::path& asm_file) {}

Assembler::Assembler(std::string& asm_code) : asm_code(asm_code) {}

std::vector<uint32_t> Assembler::assemble() {}

int Assembler::write(std::filesystem::path& outpath) {}