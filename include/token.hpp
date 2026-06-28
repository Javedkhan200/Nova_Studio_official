#pragma once
#include <string>

enum class TokenType {
    NOVA_SHOW, NOVA_ASK_USER, NOVA_ASK, NOVA_SYSTEM,
    NOVA_THREAD_START, NOVA_THREAD_JOIN, NOVA_OS_KERNEL, NOVA_AI_TRAIN,
    IDENTIFIER, STRING, LPAREN, RPAREN, END_OF_FILE, UNKNOWN, ERROR
};

struct Token {
    TokenType type;
    std::string value;
};
