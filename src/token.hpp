#pragma once
#include <string>

enum class TokenType { IDENTIFIER, STRING, NUMBER, KEYWORD, SYMBOL, END };

struct Token {
    TokenType type;
    std::string value;
};
