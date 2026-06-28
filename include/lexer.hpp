#pragma once
#include "token.hpp"
#include <vector>
#include <string>

class Lexer {
public:
    Lexer(const std::string& source);
    std::vector<Token> tokenize();
private:
    std::string source;
    size_t pos = 0;
    char peek();
    char advance();
    void skip_whitespace();
};
