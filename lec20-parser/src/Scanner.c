#include <stdio.h>
#include <ctype.h>

#include "Scanner.h"

Scanner Scanner_value(CharItr char_itr)
{
    char next = CharItr_next(&char_itr);
    Scanner scanner = {
        char_itr,
        next
    };
    return scanner;
}

bool Scanner_has_next(const Scanner *self)
{
    switch (self->next) {
        case EOF: 
        case '\n': 
        case '\0':
            return false;
        default:
            return true;
    }
}

Token Scanner_peek(const Scanner *self)
{
    TokenType type;
    switch (self->next) {
        case EOF: 
        case '\n': 
        case '\0':
           type = END_TOKEN;
           break; 
        case '(':
           type = LPAREN_TOKEN;
           break;
        case ')':
           type = RPAREN_TOKEN;
           break;
        case ' ':
           type = SPACE_TOKEN;
           break;
        default:
           type = CHAR_TOKEN;
           break;
    };
    Token token = {
        type,
        self->next
    };
    return token;
}

Token Scanner_next(Scanner *self)
{
    Token next = Scanner_peek(self);
    if (Scanner_has_next(self)) {
        self->next = CharItr_next(&self->char_itr);
        return next;
    } else {
        // When we reach the end, rather than error, keep returning
        // END_TOKEN values.
        return next;
    }
}
