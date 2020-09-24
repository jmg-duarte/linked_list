//
// Created by jmgduarte on 24/09/20.
//

#include "linked_list.h"

Node *create(int value) {
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

Node *middle(Node *start, Node *last) {
    if (start == NULL) {
        return NULL;
    }

    Node *slow = start;
    Node *fast = start->next;
    if (fast == NULL) {
        return slow;
    }

    while (slow != fast && fast != last) {
        fast = fast->next;
        if (fast == NULL) {
            return slow;
        }
        if (fast != last) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    return slow;
}

Node *binary_search(Node *head, int value) {
    if (head == NULL) {
        return NULL;
    }

    Node *start = head;
    Node *last = NULL;
    Node *prev = NULL;
    Node *mid = NULL;
    do {
        prev = mid;
        mid = middle(start, last);
        if (mid == NULL) {
            return prev;
        }
        if (mid->value == value) {
            return mid;
        } else if (mid->value < value) {
            start = mid->next;
        } else {
            last = mid;
        }
    } while (last == NULL || last != start);
    return prev;
}

Node *insert(Node *head, int value) {
    Node *node = create(value);
    if (head == NULL) {
        return NULL;
    }
    Node *prev = binary_search(head, value);
    if (prev == NULL) {
        return NULL;
    }
    Node *next = prev->next;
    prev->next = node;
    node->next = next;
    return node;
}

Node *append(Node *tail, int value) {
    if (tail == NULL) {
        return NULL;
    }
    if (tail->next != NULL) {
        return tail->next;
    }
    tail->next = create(value);
    return tail->next;
}


void print_list(Node *head) {
    Node *curr = head;
    if (head == NULL) {
        printf("NULL");
    }
    printf("[");
    while (true) {
        printf("%d", curr->value);
        if (curr->next != NULL) {
            printf(", ");
            curr = curr->next;
        } else {
            break;
        }
    }
    printf("]\n");
}