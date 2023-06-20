//
// Created by Ding Li on 6/13/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

struct Node {
    int data;
    struct Node* next;
};

struct Q {
    struct Node* front;
    struct Node* rear;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Queue* createQueue() {
    Queue* queue = (Queue*) malloc(sizeof(Queue));
    initQueue(queue);
    return queue;
}

// Initialize the Queue
void initQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

// Check if the Queue is empty
bool isEmpty(Queue* queue) {
    return (queue->front == NULL);
}

// Enqueue an element into the Queue
void enqueue(Queue* queue, int data) {
    struct Node* newNode = createNode(data);

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Dequeue an element from the Queue
void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty, cannot dequeue.\n");
        return;
    }

    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }
}

// Get the front element of the Queue
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Error: Queue is empty, no front element.\n");
        return -1;
    }

    return queue->front->data;
}

// Print the Queue
void printQueue(Queue* queue) {
    struct Node* temp = queue->front;

    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void freeQueue(Queue* queue) {
    while(!isEmpty(queue)) {
        dequeue(queue);
    }
    free(queue);
}