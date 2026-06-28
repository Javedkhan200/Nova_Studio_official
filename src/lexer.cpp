#include "lexer.hpp"
#include <regex>

std::vector<Token> Lexer::tokenize(const std::string& source) {
    std::vector<Token> tokens;
    tokens.push_back({TokenType::STRING, source});
    return tokens;
}
