#include <bytecodeio/bytecodeio.hxx>
#include <vm/vm.hxx>

int main(int argc, char** argv) {

        // if (argc <= 1) {
        //         std::cerr << "Please enter the path to the bytecode"
        //                   << std::endl;
        //         return -1;
        // }

        std::vector<uint32_t> input = {0x0C12ff00, 0x0C11ff00, 0x04121212,
                                       0x04121112, 0x0C010100, 0x07010000,
                                       0x0A011205, 0x00000000};
        // ByteCodeIO bc_buffer_1 = ByteCodeIO(argv[1]);
        // bc_buffer_1.write(input);
        //
        // ByteCodeIO bc_buffer_2 = ByteCodeIO(argv[1]);
        // std::vector<uint32_t> input;
        // input.reserve(20);
        // input = bc_buffer_2.read();

        VM x = VM(input);
        x.run();

        return 0;
}
