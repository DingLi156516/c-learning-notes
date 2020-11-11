#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

void copyString(char *to, char *from) {
    while (*from) {
        *to++ = *from++;
    }

    *to = '\0';
}

void swap(int *x, int *y);

int stringLength(const char *string);

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
    printf("The enum value is %c\n", myColor);

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

    int value2 = 232;
    // the pointer itself can't be changed
    int *const pValue2 = &value2;
    int value3 = 323;
    // will error out
    // pValue2 = &value3;
    *pValue2 = value3;

    // void pointer
    int i = 20;
    float f = 2.34f;
    char cha = 'k';
    void *vP;
    vP = &i;
    printf("i's value is %d\n", *(int *) vP);
    vP = &f;
    printf("f's value is %f\n", *(float *) vP);
    vP = &cha;
    printf("cha's value is %c\n", *(char *) vP);

    // pointers and arrays
    int values[100] = {1, 2, 3};
    int *valuesPr;
    valuesPr = values;
    printf("*valuesPr's value is %d\n", *valuesPr);
    printf("valuesPr[1]'s value is %d\n", valuesPr[1]);
    printf("*(valuesPr + 1)'s value is %d\n", *(valuesPr + 1));

    int sum = 0;
    for (int j = 0; j < sizeof(values) / sizeof(int); ++j) {
        sum += valuesPr[j];
    }
    printf("sum's value is %d\n", sum);

    //pointers and strings
    char string1[] = "A String to be copied";
    char string2[50];

    copyString(string2, string1);
    printf("string2's value is %s\n", string2);

    printf("stringLength()'s value for \"string length test\" is %d\n", stringLength("string length test"));

    // pass by reference
    int x = 1, y = 2;
    printf("Before swap, x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap, x = %d, y = %d\n", x, y);

    // malloc, realloc
    char *string = (char *) malloc(15 * sizeof(char));
    strcpy(string, "DingLi");
    printf("string = %s, address = %p\n", string, string);

    string = (char *) realloc(string, 25 * sizeof(char));
    strcat(string, ".com");
    printf("after realloc, string = %s, address = %p\n", string, string);
}

int stringLength(const char *string) {
    const char *lastAddress = string;
    while (*lastAddress)
        lastAddress++;
    return (int) (lastAddress - string);
}

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
