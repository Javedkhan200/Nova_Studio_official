#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <string>
#include <vector>
#include <string_view>

enum class TokenType { IDENTIFIER, STRING, EQUALS, DOT, LPAREN, RPAREN, END_OF_FILE, UNKNOWN };

struct Token {
    TokenType type;
    std::string value;
};

class Lexer {
private:
    std::string_view source;
    size_t pos = 0;

public:
    Lexer(std::string_view src) : source(src) {}

    std::vector<Token> tokenize() {
        std::vector<Token> tokens;
        while (pos < source.length()) {
            char current = source[pos];
            if (isspace(current)) {
                pos++;
            } else if (isalpha(current)) {
                std::string id;
                while (pos < source.length() && (isalnum(source[pos]) || source[pos] == '_')) {
                    id += source[pos++];
                }
                tokens.push_back({TokenType::IDENTIFIER, id});
            } else if (current == '=') {
                tokens.push_back({TokenType::EQUALS, "="});
                pos++;
            } else if (current == '.') {
                tokens.push_back({TokenType::DOT, "."});
                pos++;
            } else if (current == '(') {
                tokens.push_back({TokenType::LPAREN, "("});
                pos++;
            } else if (current == ')') {
                tokens.push_back({TokenType::RPAREN, ")"});
                pos++;
            } else if (current == '"') {
                std::string str;
                pos++; // Skip opening quote
                while (pos < source.length() && source[pos] != '"') {
                    str += source[pos++];
                }
                pos++; // Skip closing quote
                tokens.push_back({TokenType::STRING, str});
            } else {
                tokens.push_back({TokenType::UNKNOWN, std::string(1, current)});
                pos++;
            }
        }
        tokens.push_back({TokenType::END_OF_FILE, ""});
        return tokens;
    }
};

#endif
