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

void visit(const Node *node, size_t spaces)
{
    indent(spaces);
    switch (node->type) {
        case ERROR_NODE:
            fprintf(stderr, "Error: %s\n", node->data.error);
            break;
        case CHAR_NODE:
            printf("Char('%c')\n", node->data.value);
            break;
        case PAIR_NODE:
            printf("Pair(\n");
            visit(node->data.pair.left, spaces + 2);
            visit(node->data.pair.right, spaces + 2);
            indent(spaces);
            printf(")\n");
    }
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
