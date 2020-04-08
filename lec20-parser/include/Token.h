#ifndef TOKEN_H
#define TOKEN_H

typedef enum TokenType {
    END_TOKEN = 0,
    CHAR_TOKEN = 1,
    SPACE_TOKEN = 2,
    LPAREN_TOKEN = 3,
    RPAREN_TOKEN = 4
} TokenType;

typedef struct Token {
    TokenType type;
    char lexeme; // Normally this would be a slice!
} Token;

#endif
