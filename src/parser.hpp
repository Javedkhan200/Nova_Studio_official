#ifndef PARSER_HPP
#define PARSER_HPP

#include "lexer.hpp"
#include <memory>

struct ASTNode {
    virtual ~ASTNode() = default;
    virtual void debugPrint() = 0;
};

struct AssignmentNode : public ASTNode {
    std::string variable;
    std::string value;
    void debugPrint() override { std::cout << "Assign: " << variable << " = " << value << "\n"; }
};

struct FunctionCallNode : public ASTNode {
    std::string object;
    std::string method;
    std::string argument;
    void debugPrint() override { std::cout << "Call: " << object << "." << method << "(" << argument << ")\n"; }
};

class Parser {
private:
    std::vector<Token> tokens;
    size_t pos = 0;

public:
    Parser(std::vector<Token> tks) : tokens(tks) {}

    std::vector<std::shared_ptr<ASTNode>> parse() {
        std::vector<std::shared_ptr<ASTNode>> program;
        while (pos < tokens.size() && tokens[pos].type != TokenType::END_OF_FILE) {
            if (tokens[pos].type == TokenType::IDENTIFIER) {
                if (pos + 1 < tokens.size() && tokens[pos + 1].type == TokenType::EQUALS) {
                    auto node = std::make_shared<AssignmentNode>();
                    node->variable = tokens[pos].value;
                    if (pos + 2 < tokens.size()) {
                        node->value = tokens[pos + 2].value;
                    }
                    program.push_back(node);
                    pos += 3;
                } else if (pos + 1 < tokens.size() && tokens[pos + 1].type == TokenType::DOT) {
                    auto node = std::make_shared<FunctionCallNode>();
                    node->object = tokens[pos].value;
                    if (pos + 2 < tokens.size()) node->method = tokens[pos + 2].value;
                    if (pos + 4 < tokens.size()) node->argument = tokens[pos + 4].value; // Skip LPAREN
                    program.push_back(node);
                    pos += 6; // Skip to RPAREN
                } else {
                    pos++;
                }
            } else {
                pos++;
            }
        }
        return program;
    }
};

#endif
