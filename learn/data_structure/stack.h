//
// Created by 李鼎 on 7/6/20.
//

#ifndef LEARN_STACK_H
#define LEARN_STACK_H

struct Node {
    struct Node *next;
    int data;
};

/**
 * Global header for stack.
 */
static struct Node* head;

/**
 * current node.
 */
static struct Node* tail;

/**
 * Init the stack;
 */
void stack_init();

/**
 * Add new node to stack.
 * @param item node to be added.
 */
void stack_add(struct Node *item);

/**
 * peek the first item in the stack.
 * @return the first node to be popped.
 */
struct Node* stack_peek();

/**
 * pop the first item in the stack.
 * @return popped node.
 */
struct Node* stack_pop();

/**
 * Destroy the stack.
 */
void stack_destroy();

#endif //LEARN_STACK_H

