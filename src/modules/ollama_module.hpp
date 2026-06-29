#ifndef OLLAMA_MODULE_HPP
#define OLLAMA_MODULE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class NovaOllama {
public:
    static void generate(const std::string& model, const std::string& prompt) {
        std::cout << "[Nova Ollama] Connecting to local Ollama instance (localhost:11434)...\n";
        // cURL command to interact with local Ollama API
        std::string cmd = "curl -s -X POST http://localhost:11434/api/generate -d '{\"model\": \"" + model + "\", \"prompt\": \"" + prompt + "\", \"stream\": false}' | jq '.response'";
        std::system(cmd.c_str());
    }
};

#endif
