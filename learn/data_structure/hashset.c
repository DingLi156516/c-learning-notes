//
// Created by Ding Li on 6/20/23.
//

#include <stdlib.h>
#include "hashset.h"

#define HASH_SIZE 100

typedef struct N{
    int val;
    struct N* next;
} LinkedNode;

struct HashSet{
    LinkedNode* bucket[HASH_SIZE];
};

int hash(int key) {
    return key % HASH_SIZE;
}

LinkedNode* createLinkedNode(int key) {
    LinkedNode* node = (LinkedNode*)malloc(sizeof(LinkedNode));
    node->val = key;
    node->next = NULL;
    return node;
}

MyHashSet* myHashSetCreate() {
    MyHashSet* set = (MyHashSet*)malloc(sizeof(MyHashSet));
    for(int i = 0; i < HASH_SIZE; i++) {
        set->bucket[i] = createLinkedNode(-1);
    }
    return set;
}

LinkedNode* find(LinkedNode* cur, int key) {
    LinkedNode* prev = NULL;
    while (cur != NULL && cur->val != key) {
        prev = cur;
        cur = cur->next;
    }
    return prev;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int index = hash(key);
    LinkedNode* newNode = createLinkedNode(key);
    LinkedNode* bucket = obj->bucket[index];
    while(bucket->next != NULL && bucket->val != key) {
        bucket = bucket->next;
    }
    if(bucket->val == key) return;
    bucket->next = newNode;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int index = hash(key);
    LinkedNode* prev = find(obj->bucket[index], key);
    if(prev->next != NULL) prev->next = prev->next->next;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int index = hash(key);
    LinkedNode* bucket = obj->bucket[index];
    while(bucket != NULL) {
        if(bucket->val == key) return true;
        bucket = bucket->next;
    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    for(int i = 0; i < HASH_SIZE; i++) {
        LinkedNode* cur = obj->bucket[i];
        while(cur != NULL) {
            LinkedNode* temp = cur;
            cur = cur->next;
            free(temp);
        }
    }
    free(obj);
}
