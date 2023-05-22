#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "data_structure/stack.h"
#include "data_structure/string.h"

#define TAXRATE 0.015

#define NUM_ELEM(x) (sizeof (x) / sizeof (*(x)))

typedef int (*MyFunctionType)(int, void *);      /* a typedef for a function pointer */

#define THE_BIGGEST 100

void handler(int signum) {
    printf("Signal received %d, coming out...\n", signum);
    exit(1);
}

int DoSomethingNice(int aVariable, MyFunctionType aFunction, void *dataPointer) {
    int rv = 0;
    if (aVariable < THE_BIGGEST) {
        /* invoke function through function pointer (old style) */
        rv = (*aFunction)(aVariable, dataPointer);
    } else {
        /* invoke function through function pointer (new style) */
        rv = aFunction(aVariable, dataPointer);
    };
    return rv;
}

typedef struct {
    int colorSpec;
    char *phrase;
} DataINeed;

int TalkJive(int myNumber, void *someStuff) {
    /* recast void * to pointer type specifically needed for this function */
    DataINeed *myData = someStuff;
    printf("myData color: %d\n", myData->colorSpec);
    /* talk jive. */
    return 5;
}

static int Z = 0;

int *pointer_to_Z(int x) {
    /* function returning integer pointer, not pointer to function */
    return &Z;
}

int get_Z(int x) {
    return Z;
}

int sum(int input_array[], size_t length) {
    int sum_so_far = 0;
    int i;
    for (i = 0; i < length; i++) {
        sum_so_far += input_array[i];
    };
    return (sum_so_far);
}

enum color {
    green,
    red,
    blue
};

void testEnum() {
    typedef enum color {
        red,
        orange,
        yellow,
        green,
        cyan,
        blue,
        purple,
    } crayon_color;

    crayon_color current = red;
    printf("Current color: %d\n", current);

}

struct MyStruct {
    int m_aNumber;
    float num2;
};

void stack_test() {
    printf("*************************stack test start******************************\n");
    printf("\n");
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
    struct Node *pop_value1 = stack_pop();
    struct Node *pop_value2 = stack_pop();
    struct Node *pop_value3 = stack_pop();
    printf("peek value: %d\n", peek_value->data);
    printf("pop value: %d\n", pop_value->data);
    printf("pop value: %d\n", pop_value1->data);
    printf("pop value: %d\n", pop_value2->data);
    printf("pop value: %d\n", pop_value3->data);
    printf("is empty: %s\n", isEmpty() ? "true" : "false");

    stack_destroy();
    printf("*************************stack test end******************************\n");
}

void copyString(char *to, char *from) {
    while (*from) {
        *to++ = *from++;
    }

    *to = '\0';
}

void swap(int *x, int *y);

int stringLength(const char *string);

void pointer_to_function();

void size_of_test();

void malloc_test();

void signal_test();

void string_test();

static struct MyStruct val1, val2, val3, val4;

struct MyStruct *ASillyFunction(int b) {
    struct MyStruct *myReturn;

    if (b == 1) myReturn = &val1;
    else if (b == 2) myReturn = &val2;
    else if (b == 3) myReturn = &val3;
    else myReturn = &val4;

    return myReturn;
}

/**
 * main function to show some basic c concepts
 * @return
 */
int main() {

    testEnum();
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
    (*pNumber)++;
    printf("(*pNumber)++: %d\n", *pNumber);
    printf("before *pNumber++, pNumber is %p\n", pNumber);
    *pNumber++;
    printf("after *pNumber++, pNumber is %p\n", pNumber);
    printf("what pNumber is pointing to: %d\n", *pNumber);


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
    // but the value it points to can be changed
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

    //pointers returned from a function
    //when returning a pointer from a function, do not return a pointer that points to a value that is local to the
    // function or that is a pointer to a function argument. Pointers to local variables become invalid when the
    // function exits. In the above function, the value returned points to a static variable.
    // Returning a pointer to dynamically allocated memory is also valid
    struct MyStruct *strPointer;
    strPointer = ASillyFunction(3);
    printf("var3's address: %p\n", &val3);
    printf("strPointer's value: %p\n", strPointer);

    // When declaring parameters to functions, declaring an array variable without a size is equivalent to declaring
    // a pointer
    /* Two equivalent function prototypes */
    int LittleFunction(int *paramN);
    int LittleFunction(int paramN[]);

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

    // We want to have a two-dimensional array, but we don't need to have all the rows the same length. What we do
    //  is declare an array of pointers. The second line below declares A as an array of pointers. Each pointer points to a float.
    float linearA[30];
    float *A[6];

    A[0] = linearA;              /*  5 - 0 = 5 elements in row  */
    A[1] = linearA + 5;          /* 11 - 5 = 6 elements in row  */
    A[2] = linearA + 11;         /* 15 - 11 = 4 elements in row */
    A[3] = linearA + 15;         /* 21 - 15 = 6 elements        */
    A[4] = linearA + 21;         /* 25 - 21 = 4 elements        */
    A[5] = linearA + 25;         /* 30 - 25 = 5 elements        */

    A[3][2] = 3.66f;          /* assigns 3.66 to linearA[17];     */
    A[3][-3] = 1.44f;         /* refers to linearA[12];
                             negative indices are sometimes useful. But avoid using them as much as possible. */

    printf("linearA[17] is %f\n", linearA[17]);
    printf("linearA[12] is %f\n", linearA[12]);

    //pointers and strings
    char string1[] = "A String to be copied";
    char string2[50];

    copyString(string2, string1);
    printf("string2's value is %s\n", string2);

    printf("stringLength()'s value for \"string length test\" is %d\n", stringLength("string length test"));

    //pointers to functions
    pointer_to_function();

    // sizeof function
    size_of_test();

    // malloc
    malloc_test();

    string_test();

    // pass by reference
    int x = 1, y = 2;
    printf("Before swap, x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap, x = %d, y = %d\n", x, y);

    //structure
    struct time {
        int hour;
        int minute;
        int second;
    };
    struct date {
        int month;
        int day;
        int year;
        struct time theTime;
    };
    struct time newTime = {.hour = 13, .minute = 20, .second = 15};
    struct date today = {.year = 2020, .month = 9, .day = 20, .theTime = newTime};
    printf("today: %d-%d-%d, time is %d:%d:%d\n", today.year, today.month, today.day, today.theTime.hour,
           today.theTime.minute, today.theTime.second);
    today = (struct date) {9, 25, 2020};
    printf("after change, today: %d-%d-%d, time is %d:%d:%d\n", today.year, today.month, today.day, today.theTime.hour,
           today.theTime.minute, today.theTime.second);

    struct date *datePr;
    datePr = &today;
    printf("datePr: %d-%d-%d, time is %d:%d:%d\n", datePr->year, datePr->month, datePr->day, datePr->theTime.hour,
           datePr->theTime.minute, datePr->theTime.second);

    // access files
    FILE *filePr = fopen("/Applications/Old MAC/CS/C/c-learning-notes/myfile.txt", "r");
    if (filePr == NULL) {
        perror("Error in opening file");
        return -1;
    }
    char line[256];  // Assuming a maximum line length of 255 characters
    // Read and print each line until the end of the file
    while (fgets(line, sizeof(line), filePr) != NULL) {
        printf("%s", line);
    }
    fclose(filePr);
    filePr = NULL;

    // signal
    signal_test();
}

void string_test() {
    String *s = create_string("test");
    printf("string struct data: %s\n", get_data(s));
    free_string(s);
}

void signal_test() {
    signal(SIGINT, handler); // attaching the handler() function to SIGINT signals; i.e, ctrl+c, keyboard interrupt.

    while(1) {
        printf("Sleeping...\n");
        sleep(1000); // sleep pauses the process for a given number of seconds, or until a signal is received.
    }
}

void malloc_test() {
    // malloc, realloc
    char *string = (char *) malloc(15 * sizeof(char));
    if (string == NULL) {
        printf("Out of memory, exiting...\n");
        exit(1);
    }
    strcpy(string, "DingLi");
    printf("string = %s, address = %p\n", string, string);

    string = (char *) realloc(string, 25 * sizeof(char));
    if (string == NULL) {
        printf("Out of memory, exiting...\n");
        exit(1);
    }
    strcat(string, ".com");
    printf("after realloc, string = %s, address = %p\n", string, string);
    free(string);
}

void size_of_test() {
    int left_array[] = {1, 2, 3, 4};
    int right_array[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // the sizeof operator only works on things defined earlier in the same function
    int the_sum = sum(left_array, NUM_ELEM(left_array)); // works here, because left_array is defined in this function
    printf("the sum of left_array is: %d\n", the_sum);
    the_sum = sum(right_array, NUM_ELEM(right_array)); // works here, because right_array is defined in this function
    printf("the sum of right_array is: %d\n", the_sum);
}

int (*fpa())[] {
    // int (*fpa())[] in C represents a function named fpa that returns a pointer to an array of integers.
    static int arr[] = {1, 2, 3};
    return &arr;
}

void pointer_to_function() {
    int (*function_pointer_to_Z)(int); // pointer to function taking an int as argument and returning an int
    function_pointer_to_Z = &get_Z;

    printf("pointer_to_Z output: %d\n", *pointer_to_Z(3));
    printf("function_pointer_to_Z output: %d\n", (*function_pointer_to_Z)(3));

    static DataINeed sillyStuff = {blue, "Whatcha talkin 'bout Willis?"};
    DoSomethingNice(41, &TalkJive, &sillyStuff);

    int (*result)[] = fpa();

    // Accessing the elements
    printf("%d\n", (*result)[1]); // Output: 2
    /*
    int i;          // integer variable 'i'
    int *p;         // pointer 'p' to an integer
    int a[];        // array 'a' of integers
    int f();        // function 'f' with return value of type integer
    int **pp;       // pointer 'pp' to a pointer to an integer
    int (*pa)[];    // pointer 'pa' to an array of integer
    int (*pf)();    // pointer 'pf' to a function with return value integer
    int *ap[];      // array 'ap' of pointers to an integer
    int *fp();      // function 'fp' which returns a pointer to an integer
    int ***ppp;     // pointer 'ppp' to a pointer to a pointer to an integer
    int (**ppa)[];  // pointer 'ppa' to a pointer to an array of integers
    int (**ppf)();  // pointer 'ppf' to a pointer to a function with return value of type integer
    int *(*pap)[];  // pointer 'pap' to an array of pointers to an integer
    int *(*pfp)();  // pointer 'pfp' to function with return value of type pointer to an integer
    int **app[];    // array of pointers 'app' that point to pointers to integer values
    int (*apa[])[]; // array of pointers 'apa' to arrays of integers
    int (*apf[])(); // array of pointers 'apf' to functions with return values of type integer
    int ***fpp();   // function 'fpp' which returns a pointer to a pointer to a pointer to an int
    int (*fpa())[]; // function 'fpa' with return value of a pointer to array of integers
    int (*fpf())(); // function 'fpf' with return value of a pointer to function which returns an integer
    */
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
