#pragma once
#include "token.hpp"
#include <vector>
#include <unordered_map>
#include <string>
#include <stdexcept>

class Runtime {
public:
    void execute(const std::vector<Token>& tokens);
private:
    std::unordered_map<std::string, std::string> env;
    void expect(const std::vector<Token>& tokens, size_t pos, TokenType type, const std::string& err);
};
