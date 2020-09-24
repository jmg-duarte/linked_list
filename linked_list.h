//
// Created by jmgduarte on 24/09/20.
//

#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;

struct Node {
    int value;
    Node *next;
};

Node *create(int value);

Node *middle(Node *head, Node *last);

Node *binary_search(Node *head, int value);

Node *insert(Node *head, int value);

Node *append(Node *tail, int value);

void print_list(Node* head);

#endif //LINKED_LIST_LINKED_LIST_H
