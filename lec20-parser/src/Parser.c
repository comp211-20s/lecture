#include "Parser.h"
#include "Token.h"

// NODE         ::= CHAR_NODE | PAIR_NODE
// CHAR_NODE    ::= CHAR_TOKEN
// PAIR_NODE    ::= LPAREN_TOKEN NODE SPACE_TOKEN NODE RPAREN_TOKEN

static Node* parse_pair(Scanner *scanner);
static Node* parse_char(Scanner *scanner);

Node* parse(Scanner *scanner)
{
    Token next = Scanner_peek(scanner);
    switch (next.type) {
        case LPAREN_TOKEN:
            return parse_pair(scanner);
        case RPAREN_TOKEN:
            return ErrorNode_new("Unexpected )");
        case SPACE_TOKEN:
            return ErrorNode_new("Unexpected Space");
        default:
            return parse_char(scanner);
    }
}

static Node* parse_char(Scanner *scanner)
{
    Token next = Scanner_next(scanner);
    if (next.type != CHAR_TOKEN) {
        return ErrorNode_new("Expected Char");
    }
    return CharNode_new(next.lexeme);
}

static Node* parse_pair(Scanner *scanner)
{
    Token next;

    next = Scanner_next(scanner);
    if (next.type != LPAREN_TOKEN) {
        return ErrorNode_new("Expected (");
    }

    Node *left = parse(scanner);
    if (left->type == ERROR_NODE) {
        return left;
    }

    next = Scanner_next(scanner);
    if (next.type != SPACE_TOKEN) {
        Node_drop(left);
        return ErrorNode_new("Expected space");
    }

    Node *right = parse(scanner);
    if (right->type == ERROR_NODE) {
        Node_drop(left);
        return right;
    }

    next = Scanner_next(scanner);
    if (next.type != RPAREN_TOKEN) {
        Node_drop(left);
        Node_drop(right);
        return ErrorNode_new("Expected )");
    }

    return PairNode_new(left, right);
}
