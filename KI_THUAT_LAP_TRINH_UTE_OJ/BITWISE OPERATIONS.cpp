/*Cre : BlackboxAI*/
#include <iostream>
#include <string>
#include <cstdint>
int main() {
    int q;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        uint32_t a, b;
        std::string command;
        std::cin >> a >> command >> b;

        if (command == "AND") {
            std::cout << (a & b) << std::endl;
        } else if (command == "OR") {
            std::cout << (a | b) << std::endl;
        } else if (command == "XOR") {
            std::cout << (a ^ b) << std::endl;
        } else if (command == "NOT") {
            std::cout << (~a ^ ~b) << std::endl;
        } else if (command == "LEFT") {
            std::cout << (a << b) << std::endl;
        } else if (command == "RIGHT") {
            std::cout << (a >> b) << std::endl;
        }
    }

    return 0;
}