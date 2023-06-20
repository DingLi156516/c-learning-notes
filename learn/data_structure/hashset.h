//
// Created by Ding Li on 6/20/23.
//

#include <stdbool.h>

#ifndef LEARN_HASHSET_H
#define LEARN_HASHSET_H
typedef struct HashSet MyHashSet;
MyHashSet* myHashSetCreate();
void myHashSetAdd(MyHashSet* obj, int key);
void myHashSetRemove(MyHashSet* obj, int key);
bool myHashSetContains(MyHashSet* obj, int key);
void myHashSetFree(MyHashSet* obj);
#endif //LEARN_HASHSET_H
