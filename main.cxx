#include <iostream>
#include <vm/vm.hxx>

int main() {
        uint64_t program[] = {0x0D674300, 0x0D027B00, 0x01670200, 0x0D0C0A00,
                              0x010C0C01, 0x01000102, 0x69000000};

        VM x = VM(program);
        x.run();
}