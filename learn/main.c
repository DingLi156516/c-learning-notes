#include <stdio.h>
#include <string.h>
#include "data_structure/stack.h"

#define TAXRATE 0.015

int encrypt(int c, int base) {
    c -= base;
    c += 13;
    c %= 26;
    return c + base;
}

enum color {
    green,
    red,
    blue
};

void stack_test() {
    stack_init();
    struct Node node1 = {.data = 1};
    struct Node node2 = {.data = 2};
    struct Node node3 = {.data = 3};
    struct Node node4 = {.data = 4};
    stack_add(&node1);
    stack_add(&node2);
    stack_add(&node3);
    stack_add(&node4);
    struct Node *peek_value = stack_peek();
    struct Node *pop_value = stack_pop();
    printf("peek value: %d\n", peek_value->data);
    printf("pop value: %d\n", pop_value->data);
    stack_destroy();
}

/**
 * main function to show some basic c concepts
 * @return
 */
int main() {
//    int c;
//    while((c = getchar()) != EOF) {
//        if (c >= 'A' && c <= 'Z') {
//            c = encrypt(c, 'A');
//        } else if(c >= 'a' && c <= 'z') {
//            c = encrypt(c, 'a');
//        }
//        putchar(c);
//    }

    // stack test
    stack_test();

    // string test
//    char input[100];
//    printf("Please input your name: ");
//    gets(input);
//    printf("Hello, %s\n", input);

    // string functions
    char s[20] = "Da shuai bi shi wo";
    printf("String length is %lu\n", strlen(s));
    char copy[20];
    strcpy(copy, s);
    printf("Copied string using strcpy is %s\n", copy);
    memset(copy, 0, 20);
    strncpy(copy, s, 10);
    printf("Copied string using strncpy is %s\n", copy);


    // random
    printf("Tax rate: %f\n", TAXRATE);
    enum color myColor = green;
    printf("The enum value is %d\n", myColor);

    // strchr()
    char str[] = "The quick brown fox";
    char ch = 'q';
    char *pGot_Char = NULL;
    pGot_Char = strchr(str, ch);
    printf("pGot_Char is : %c\n", *pGot_Char);
    // strstr()
    char str1[] = "The quick brown fox";
    char substr[] = "quick";
    char *pFound = NULL;
    pFound = strstr(str1, substr);
    printf("pGot_Char is : %s\n", pFound);

    //pointer
    int number = 99;
    int *pNumber = &number;
    int **ppNumber = &pNumber;
    printf("number's value is %d\n", number);
    printf("number's address is %p\n", pNumber);
    printf("number's address's address is %p\n", ppNumber);
    printf("number's address has %lu bytes\n", sizeof(pNumber));

    long value = 100L;
    const long *pValue = &value;
    // the value pointed to must not be changed
    // this will fail
    // *pValue = 200L;
    value = 200L;
    // the pointer itself is not constant
    long value1 = 300L;
    pValue = &value1;

    int value2 = 232L;
    // the pointer itself can't be changed
    int *const pValue2 = value2;
    int value3 = 323L;
    // will error out
    // pValue2 = &value3;
    *pValue2 = 2323L;


}


