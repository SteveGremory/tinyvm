#include <bytecodeio/bytecodeio.hxx>
#include <vm/vm.hxx>

void print_help() {
        std::cout << "TinyVM: A SteveGremory creation." << std::endl
                  << "TinyVM is a basic register based VM that "
                     "interprets the bytecode it's given."
                  << std::endl
                  << "h or help: Print this message" << std::endl
                  << "write_example: writes some bytecode to an example file."
                  << std::endl
                  << "[filename]: Path to the bytecode to be executed."
                  << std::endl;
}

int main(int argc, char** argv) {

        if (argc <= 1) {
                print_help();
                return -1;
        }

        std::string argvstr{argv[1]};

        // Eh just doing it in the simplest way for now
        if (argvstr == "write_example") {
                std::vector<uint32_t> input = {
                    0x0C12ff00, 0x0C11ff00, 0x04121212, 0x04121112, 0x0C010100,
                    0x07010000, 0x0A011205, 0x14010000, 0x00000000};

                ByteCodeIO bc_buffer = ByteCodeIO("main.bytecode");
                bc_buffer.write(input);

                std::cout << "This example calculates the cube of 0xFF (255) "
                             "and then increments a register until it is equal "
                             "to the cube of 255."
                          << std::endl;

                return 0;
        } else if (argvstr == "help" || argvstr == "h") {
                print_help();
        } else if (!std::filesystem::exists(argvstr)) {
                std::cerr << "Please enter a valid file path." << std::endl;
                return -1;
        }

        ByteCodeIO bc_buffer = ByteCodeIO(argvstr);

        std::vector<uint32_t> input = {0};
        input.reserve(20);

        input = bc_buffer.read();

        VM x = VM(input);
        x.run();

        return 0;
}
