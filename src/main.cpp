#include <iostream>
#include <fstream>
#include <string>
#include "runtime.hpp"

void printHeader() {
    std::cout << "\033[1;36mNova Singularity Engine v1.0 | Architect: Jack | Commercial Edition\033[0m\n";
}

int main(int argc, char* argv[]) {
    Runtime runtime;

    if (argc > 1) {
        std::string arg = argv[1];
        if(arg == "-v" || arg == "--version") {
            printHeader();
            return 0;
        }
        std::ifstream file(argv[1]);
        if (!file.is_open()) {
            std::cerr << "\033[1;31mError: Could not open file " << argv[1] << "\033[0m\n";
            return 1;
        }
        std::string line;
        while (std::getline(file, line)) {
            runtime.executeLine(line);
        }
    } else {
        printHeader();
        std::string input;
        while (true) {
            std::cout << "\033[1;32mnova>\033[0m ";
            if (!std::getline(std::cin, input)) break;
            if (input == "exit" || input == "quit") break;
            runtime.executeLine(input);
        }
    }
    return 0;
}
