//
// Created by 李鼎 on 7/6/20.
//

#include "stack.h"
#include "stdlib.h"

void stack_init() {
    head = (struct Node *) malloc(sizeof(struct Node));
    head->next = NULL;
    head->data = 0;
    tail = head;
}

void stack_add(struct Node *node) {
    if (tail == head) {
        tail = node;
        head->next = tail;
    } else {
        struct Node *temp = head->next;
        head->next = node;
        node->next = temp;
    }
}

struct Node *stack_peek() {
    return head->next;
}

struct Node *stack_pop() {
    struct Node *pop = head->next;
    head->next = pop->next;
    pop->next = NULL;
    return pop;
}

void stack_destroy() {
    while (head->next != tail) {
        struct Node *temp = head->next;
        head->next = temp->next;
    }
    tail = NULL;
    free(head);
}
