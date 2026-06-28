#include <iostream>
#include <string>
#include "runtime.hpp"

int main() {
    Runtime runtime;
    std::string input;
    // परमानेंट हेडर और कॉपीराइट
    std::cout << "\033[1;36mNova Singularity v1.0 | Architect: Javed | (c) 2026 Nova Studio. All Rights Reserved.\033[0m\n";
    std::cout << "Type 'exit' to quit.\n";
    while (true) {
        std::cout << "\033[1;32m>>> \033[0m"; // कलरफुल REPL प्रॉम्प्ट
        if (!std::getline(std::cin, input) || input == "exit") break;
        runtime.executeLine(input);
    }
    return 0;
}
