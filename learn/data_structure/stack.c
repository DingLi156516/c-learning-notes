//
// Created by 李鼎 on 7/6/20.
//

#include "stack.h"
#include "stdlib.h"

void stack_init() {
    head = (struct Node *) malloc(sizeof(struct Node));
    tail = (struct Node *) malloc(sizeof(struct Node));
    head->next = tail;
    head->data = 0;
    tail->data = 0;
}

void stack_add(struct Node *node) {
    struct Node *temp = head->next;
    head->next = node;
    node->next = temp;
}

struct Node *stack_peek() {
    if(head->next == tail) {
        return NULL;
    } else {
        return head->next;
    }
}

struct Node *stack_pop() {
    if (head->next == tail) {
        return NULL;
    } else {
        struct Node *pop = head->next;
        head->next = pop->next;
        pop->next = NULL;
        return pop;
    }
}

void stack_destroy() {
    while (head->next != tail) {
        struct Node *temp = head->next;
        head->next = temp->next;
    }
    free(tail);
    free(head);
}

bool stack_isEmpty() {
    return head->next == tail;
}
