#include "lexer.hpp"
#include "parser.hpp"
#include "runtime.hpp"
#include "modules/ai_module.hpp"
#include "modules/gui_renderer.hpp"
#include "modules/game_api.hpp"
#include "modules/interop_bridge.hpp"
#include "modules/ollama_module.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

/*
 * Nova Language - AI-Native Scripting Engine
 * Copyright (c) 2026 Jack (Architect). All rights reserved.
 */

void print_copyright() {
    std::cout << "Nova 1.0.4 (default, Jun 29 2026, 13:12:02) [GCC 14.2.1] on Termux/Linux\n";
    std::cout << "Type \"help\", \"copyright\", \"credits\" or \"license\" for more information.\n";
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::ifstream file(argv[1]);
        if (file) {
            std::stringstream buffer;
            buffer << file.rdbuf();
            std::string sourceCode = buffer.str();
            Lexer lexer(sourceCode);
            auto tokens = lexer.tokenize();
            Parser parser(tokens);
            auto ast = parser.parse();
            NovaRuntime runtime;
            runtime.evaluate(ast);
        }
        return 0;
    }

    print_copyright();
    NovaRuntime runtime;
    std::string input;
    while (true) {
        std::cout << ">>> ";
        std::getline(std::cin, input);
        
        if (input == "exit" || input == "quit") break;
        if (input == "copyright") { std::cout << "Copyright (c) 2026 Jack. All Rights Reserved.\n"; continue; }
        if (input.empty()) continue;

        Lexer lexer(input);
        auto tokens = lexer.tokenize();
        Parser parser(tokens);
        auto ast = parser.parse();
        runtime.evaluate(ast);
    }
    return 0;
}
