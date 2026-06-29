#include "lexer.hpp"
#include "parser.hpp"
#include "runtime.hpp"
#include <iostream>
#include <string>

/*
 * Nova Language - AI-Native Scripting Engine
 * Copyright (c) 2026 Jack (Architect). All rights reserved.
 */

void print_header() {
    std::cout << "Nova 1.0.7 (default, Jun 29 2026) [GCC 14.2.1] on Termux/Linux\n";
    std::cout << "Type \"help\", \"copyright\", \"credits\" or \"license\" for more information.\n";
}

int main() {
    print_header();
    NovaRuntime runtime;
    std::string input;
    
    while (true) {
        std::cout << ">>> "; // Python-style prompt
        std::getline(std::cin, input);
        
        if (input == "exit" || input == "quit") break;
        if (input == "copyright") { 
            std::cout << "Copyright (c) 2026 Jack (Architect). All Rights Reserved.\n"; 
            continue; 
        }
        if (input.empty() || input[0] == '#') continue;

        Lexer lexer(input);
        auto tokens = lexer.tokenize();
        Parser parser(tokens);
        auto ast = parser.parse();
        runtime.evaluate(ast);
    }
    return 0;
}
