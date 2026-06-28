#pragma once
#include <string>
#include <unordered_map>
#include <iostream>

class Runtime {
private:
    std::unordered_map<std::string, std::string> variables;
    std::string callGeminiAPI(const std::string& prompt);
public:
    void executeLine(const std::string& line);
};
