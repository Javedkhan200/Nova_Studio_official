#pragma once
#include <vector>
#include <string>
#include "token.hpp"

class Lexer {
public:
    std::vector<Token> tokenize(const std::string& source);
};
