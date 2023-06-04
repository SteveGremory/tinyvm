#include "memory/memory.hxx"

#include <iostream>

int main() {
        int x = 10;
        Stack<int> s;

        for (int i = 0; i <= 512000; i++)
                s.push(x);

        int z{1230};
        s.push(z);

        std::cout << s.at(STACK_MAX_SIZE - 1) << std::endl;
}