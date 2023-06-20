//
// Created by Ding Li on 6/13/23.
//

#ifndef LEARN_QUEUE_H
#define LEARN_QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Q Queue;
Queue* createQueue();
void initQueue(Queue* queue);
bool isEmpty(Queue* queue);
void enqueue(Queue* queue, int data);
void dequeue(Queue* queue);
int front(Queue* queue);
void printQueue(Queue* queue);
void freeQueue(Queue* queue);
#endif //LEARN_QUEUE_H


