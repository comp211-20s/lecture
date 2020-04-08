#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "CharItr.h"
#include "Scanner.h"
#include "Node.h"
#include "Parser.h"

#define MAX_LINE_LENGTH 1024
static char buffer[MAX_LINE_LENGTH];

/* Read a line up to max_length into buffer */
bool read_next_line(char *buffer, size_t max_length);

/* Helper to print a Token */
void visit(const Node *node, size_t spaces);

/* Helper to indent output by n_spaces */
void indent(size_t n_spaces);

int main() {
    while (read_next_line(buffer, MAX_LINE_LENGTH)) {
        CharItr itr = CharItr_value(buffer, strlen(buffer));
        Scanner scanner = Scanner_value(itr);
        Node *node = parse(&scanner);
        visit(node, 0);
        Node_drop(node);
    }
}

// Original Input String:
// (a (b c))
//
// Expected visit Output:
// 
// Pair(
//   Char('a')
//   Pair(
//     Char('b')
//     Char('c')
//   )
// )
void visit(const Node *node, size_t spaces)
{
    // TODO
}

void indent(size_t spaces)
{
    for (size_t i = 0; i < spaces; ++i) {
        putchar(' ');
    }
}

bool read_next_line(char *buffer, size_t max_length) {
    return fgets(buffer, max_length, stdin) != NULL;
}
