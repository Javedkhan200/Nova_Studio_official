#include "runtime.hpp"
#include <iostream>
#include <regex>
#include <cstdlib>

void Runtime::executeLine(const std::string& line) {
    if (line.empty() || line[0] == '#') return;
    std::smatch m;

    // 1. API Key Set
    if (std::regex_search(line, m, std::regex(R"(api_key\s*=\s*(.+))"))) {
        variables["API_KEY"] = m[1];
        return;
    }

    // 2. Nova.ai.think(variable) - तुम्हारा नया AI सिंटैक्स
    if (std::regex_search(line, m, std::regex(R"(Nova\.ai\.think\(([a-zA-Z_][a-zA-Z0-9_]*)\))"))) {
        std::string var_name = m[1];
        std::string content = variables[var_name];
        
        std::cout << "\033[1;35m[Nova AI Brain]\033[0m Thinking about: " << content << "..." << std::endl;
        
        std::string cmd = "curl -s -X POST https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash:generateContent?key=" 
                          + variables["API_KEY"] + " -H 'Content-Type: application/json' -d '{\"contents\":[{\"parts\":[{\"text\":\"" 
                          + content + "\"}]}]}' | jq -r '.candidates[0].content.parts[0].text'";
        
        std::cout << "\033[1;32m>> \033[0m";
        std::system(cmd.c_str());
        return;
    }

    // 3. Simple Assignment (g = 50)
    if (std::regex_search(line, m, std::regex(R"(^([a-zA-Z_][a-zA-Z0-9_]*)\s*=\s*(.+)$)"))) {
        variables[m[1]] = m[2];
        return;
    }
}
