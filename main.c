#include <pthread.h>

#include "linked_list.h"

void *insert_even(void *head) {
    Node* h = (Node*) head;
    for (int i = 0; i < 10; i+=2) {
        insert(h, i);
    }
}

void *insert_uneven(void *head) {
    Node* h = (Node*) head;
    for (int i = 1; i < 10; i+=2) {
        insert(h, i);
    }
}

int main() {
    pthread_t tid_1;
    pthread_t tid_2;
    Node *head = create(-1);

    insert_uneven(head);

    pthread_create(&tid_1, NULL, insert_even, head);
    pthread_create(&tid_2, NULL, insert_uneven, head);

    pthread_join(tid_1, NULL);
    pthread_join(tid_2, NULL);

    print_list(head);
    return 0;
}
