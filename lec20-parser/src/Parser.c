#include "Parser.h"
#include "Token.h"

// Grammar
// NODE         ::= CHAR_NODE | PAIR_NODE
// CHAR_NODE    ::= CHAR_TOKEN
// PAIR_NODE    ::= LPAREN_TOKEN NODE SPACE_TOKEN NODE RPAREN_TOKEN

static Node* parse_pair(Scanner *scanner);
static Node* parse_char(Scanner *scanner);

// NODE         ::= CHAR_NODE | PAIR_NODE
Node* parse(Scanner *scanner)
{
    Token next = Scanner_peek(scanner);
    switch (next.type) {
        case CHAR_TOKEN:
            return parse_char(scanner);
        case LPAREN_TOKEN:
            return parse_pair(scanner);
        default:
            return ErrorNode_new("Expected ( or a Char");
    }
}

// CHAR_NODE    ::= CHAR_TOKEN
static Node* parse_char(Scanner *scanner)
{
    return NULL;
}

// PAIR_NODE    ::= LPAREN_TOKEN NODE SPACE_TOKEN NODE RPAREN_TOKEN
static Node* parse_pair(Scanner *scanner)
{
    return NULL;
}
