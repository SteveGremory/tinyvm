#include <bytecodeio/bytecodeio.hxx>
#include <vm/vm.hxx>

int main(int argc, char** argv) {

        // if (argc <= 1) {
        //         std::cerr << "Please enter the path to the bytecode"
        //                   << std::endl;
        //         return -1;
        // }

        /*std::vector<uint32_t> input = {
            0x0D674300, 0x0D027B00, 0x01670200, 0x0D0C0A00, 0x010C0C01,
            0x01000102, 0x06020000, 0x2C020000, 0x0A020000, 0x69000000};
            */

        /*
                // Math
                NONE = 0x0,
                ADD = 0x01, // Add one register to another
                SUB = 0x02, // Subtract one register from another
                MUL = 0x03, // Multiplication
                DIV = 0x04, // Division
                MOD = 0x05, // Mod function
                INC = 0x06, // Increment the reigster by 1
                NEG = 0x07, // Decrement the register by 1=
                JMP = 0x0A, // Unconditional Jump
                JNE = 0x0B, // Jump if both registers are NOT equal
                JE = 0x0C,  // Jump if both registers are equal=
                MOV = 0x0D, // Move
                TST = 0x0E, // Check if two registers are equal
                AND = 0x12,
                OR = 0x13,
                XOR = 0x14,
                NOT = 0x15,
                LSHIFT = 0x16,
                RSHIFT = 0x17,
                STALL = 0x69*/
        std::vector<uint32_t> input = {
            0x0D12ff00, 0x03121212, 0x03121212, 0x03121212, 0x03121212,
            0x03121212, 0x0D010100, 0x06010000, 0x0B011207, 0x69000000};

        // ByteCodeIO bc_buffer_1 = ByteCodeIO(argv[1]);
        // bc_buffer_1.write(input);
        //
        // ByteCodeIO bc_buffer_2 = ByteCodeIO(argv[1]);
        // std::vector<uint32_t> data = bc_buffer_2.read();

        VM x = VM(input);
        x.run();

        return 0;
}