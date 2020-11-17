# c-learning-notes

### 2020-10-18
1. use the pointer itself to print string
    ```c
    char* pFound = "the best"; 
    printf("string value is : %s\n", pFound);
    ```
2. simple makefile: https://www.gnu.org/software/make/manual/html_node/Simple-Makefile.html
3. leetcode: 14. Longest Common Prefix
### 2020-11-17
1. how to initialize 2 dimensional array
    ```c
    char arr[10][10] = {...};
    char *arr[10] = {...};
    ```
   you can't do char **arr, as it only means a pointer to a pointer to a char If c is a pointer to a pointer to a character, that means we have to allocate some memory in which to actually hold the array of strings
2. leetcode: 
    12. Integer to Roman 
    13. Roman to Integer
   