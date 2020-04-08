#ifndef NODE_H
#define NODE_H

typedef enum NodeType {
    ERROR_NODE = -1,
    CHAR_NODE = 0,
    PAIR_NODE = 1
} NodeType;

typedef struct Node Node; // Forward Declaration

typedef struct PairData {
    Node *left;
    Node *right;
} PairData;

typedef char CharData;

typedef const char* ErrorData;

struct Node {
    NodeType type;
    union {
        PairData pair;
        CharData value;
        ErrorData error;
    } data;
};

Node* CharNode_new(char c);

Node* PairNode_new(Node *left, Node *right);

Node* ErrorNode_new(const char *msg);

void* Node_drop(Node *self);

#endif
