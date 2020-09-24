//
// Created by jmgduarte on 24/09/20.
//

#include "linked_list_tests.h"

void insert_empty_list() {
    LOG();
    Node *head = NULL;
    assert(insert(head, 1) == NULL);
}

void insert_single_element_list() {
    LOG();
    Node *head = create(1);
    assert(head->value == 1);
    assert(insert(head, 2) != NULL);
    Node *next = head->next;
    assert(next != NULL);
    assert(next->next == NULL);
    assert(next->value == 2);
}

void insert_multiple_element_list() {
    LOG();
    Node *head = create(1);
    Node *tail = head;
    tail = append(tail, 2);
    tail = append(tail, 3);
    Node* three = tail;
    tail = append(tail, 4);
    Node* four = tail;
    tail = append(tail, 5);
    tail = append(tail, 6);
    assert(insert(head, 3) != NULL);
    assert(three->next->next == four);
    assert(three->next->value == 3);
}