#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
static char buffer[MAX_LINE_LENGTH];

/* Read a line up to max_length into buffer */
bool read_next_line(char *buffer, size_t max_length);

/* Simple API around Character Iteration */
typedef char* CharItr;

/* Are there still characters left to consume? */
bool has_next(const CharItr itr) { return *itr != '\n' && *itr != '\0'; }

/* Look ahead at the next character of input without consuming it. */
char peek(const CharItr itr) { return *itr; }

/* Consume the next character of input. */
char next(CharItr *itr) { char next = **itr; *itr += 1; return next; }

/* TokenType specifies the kinds of Tokens in our demo. */
typedef enum TokenType {
    ERROR = 0, 
    DIGIT = 1,
    LOL = 2,
} TokenType;

/* A Slice is a range of a char array. */
typedef struct Slice {
    char *start;
    size_t length;
} Slice;

/* A Token is a type and its location. */
typedef struct Token {
    TokenType type;
    Slice location; 
} Token;

/* These helper functions take an iterator to consume (and return) a Token. */
Token take_lol(CharItr *itr);
Token take_digit(CharItr *itr);
Token take_error(CharItr *itr);

/* Helper function to print a Token */
void print_token(const Token *token);

int main() {
    while (read_next_line(buffer, MAX_LINE_LENGTH)) {
        CharItr itr = buffer; // reset iterator at start of buffer
        while (has_next(itr)) {
            char c = peek(itr);
            Token token;
            switch (c) {
                case '0': case '1': case '2': case '3': case '4': 
                case '5': case '6': case '7': case '8': case '9':
                    token = take_digit(&itr);
                    break;
                case 'l':
                    token = take_lol(&itr);
                    break;
                default:
                    token = take_error(&itr);
                    break;
            }
            print_token(&token);
        }
    }
}

Token take_lol(CharItr *itr) {
    // Record start of token
    CharItr start = *itr;
    size_t length = 1;
    next(itr); // Consume the leading 'l'

    bool valid = true;
    if (peek(*itr) == 'o') {
        next(itr); // Consume the 'o'
        length += 1;
    } else {
        valid = false;
    }

    if (valid && peek(*itr) == 'l') {
        next(itr); // consume the 'l'
        length += 1;
    } else {
        valid = false;
    }

    if (valid) {
        while ((peek(*itr) == 'o' || peek(*itr) == 'l')) {
            next(itr); // consume the character
            length += 1;
        }
    }

    Slice location = {
       start,
       length 
    };

    if (valid) {
        Token token = {
            LOL,
            location
        };
        return token;
    } else {
        Token token = {
            ERROR,
            location
        };
        return token;
    }
}

Token take_digit(CharItr *itr) {
    Slice location = {
        *itr,
        1
    };
    next(itr); // Consume the character
    Token token = {
        DIGIT,
        location
    };
    return token;
}

Token take_error(CharItr *itr) {
    Slice location = {
        *itr,
        1
    };
    next(itr); // Consume the character
    Token token = {
        ERROR,
        location
    };
    return token;
}

void print_token(const Token *token) {
    switch (token->type) {
        case ERROR:
            printf("ERROR(");
            break;
        case DIGIT:
            printf("DIGIT(");
            break;
        case LOL:
            printf("LOL(");
            break;
    }
    // Since our Slice represents an inner section of a string, it does not
    // terminate with a null character. As such, to print it, we use fwrite
    // which prints a specific range of data to a stream (stdout).
    fwrite(token->location.start, sizeof(char), token->location.length, stdout);
    printf(")\n");
}

// This is a naive implementation of reading a line.
bool read_next_line(char *buffer, size_t max_length) {
    return fgets(buffer, max_length, stdin) != NULL;
}
