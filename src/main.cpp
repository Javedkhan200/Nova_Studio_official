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

int main(int argc, char* argv[]) {
    // अगर यूजर ने कोई फाइल दी है (e.g., nova app.nv)
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
        } else {
            std::cerr << "[Error] Could not read file: " << argv[1] << "\n";
        }
        return 0;
    }

    // अगर यूजर ने सिर्फ 'nova' टाइप किया है (Interactive Shell)
    std::cout << "🌌 NovaOS Engine v1.0.1 (Architect Edition)\n";
    std::cout << "Type 'exit' to close the engine.\n";
    
    NovaRuntime runtime; // Runtime एक ही बार शुरू होगा ताकि मेमोरी बनी रहे

    std::string input;
    while (true) {
        std::cout << "nova> ";
        std::getline(std::cin, input);
        
        if (input == "exit" || input == "quit") {
            std::cout << "Shutting down Nova Engine...\n";
            break;
        }
        if (input.empty()) continue;

        // रियल-टाइम एक्जीक्यूशन
        Lexer lexer(input);
        auto tokens = lexer.tokenize();
        Parser parser(tokens);
        auto ast = parser.parse();
        runtime.evaluate(ast);
    }

    return 0;
}
