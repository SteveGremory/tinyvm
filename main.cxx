#include <bytecodeio/bytecodeio.hxx>
#include <vm/vm.hxx>

int main(int argc, char** argv) {

        if (argc <= 1) {
                std::cerr << "Please enter the path to the bytecode"
                          << std::endl;
                return -1;
        }

        std::vector<uint32_t> input = {
            0x0D674300, 0x0D027B00, 0x01670200, 0x0D0C0A00, 0x010C0C01,
            0x01000102, 0x06020000, 0x2C020000, 0x0A020000, 0x69000000};

        ByteCodeIO bc_buffer_1 = ByteCodeIO(argv[1]);
        bc_buffer_1.write(input);

        ByteCodeIO bc_buffer_2 = ByteCodeIO(argv[1]);
        std::vector<uint32_t> data = bc_buffer_2.read();

        VM x = VM(data);
        x.run();

        return 0;
}