//
// Created by Ding Li on 5/18/23.
//
/* The #ifndef LEARN_STRING_H/#define LEARN_STRING_H trick is colloquially called include guards. This is used so that if the
 * getopt.h file were included more than once in a translation unit, the unit would only see the contents once */
#ifndef LEARN_STRING_H
#define LEARN_STRING_H
#define FREE(p)   do { free(p); (p) = NULL; } while(0)
#include <stddef.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
typedef struct string String;
String *create_string(const char *initial);
char* get_data(String *s);
void free_string(struct string *s);
#endif //LEARN_STRING_H
