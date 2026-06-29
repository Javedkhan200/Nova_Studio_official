#include "lexer.hpp"
#include "parser.hpp"
#include "runtime.hpp"
#include <iostream>
#include <string>

int main() {
    std::cout << "🌌 NovaOS Engine v1.0.5 (Fixed Mode)\n";
    NovaRuntime runtime;
    std::string input;
    while (true) {
        std::cout << "nova> ";
        std::getline(std::cin, input);
        if (input == "exit") break;
        if (input.empty() || input[0] == '#') continue;

        Lexer lexer(input);
        auto tokens = lexer.tokenize();
        Parser parser(tokens);
        auto ast = parser.parse();
        runtime.evaluate(ast);
    }
    return 0;
}
