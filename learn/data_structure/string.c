//
// Created by Ding Li on 5/18/23.
//
#include "string.h"

typedef struct string {
    size_t size;
    char *data;
} String;

String *create_string(const char *initial) {
    assert (initial != NULL);
    struct string *new_string = malloc(sizeof(*new_string));
    if (new_string != NULL) {
        new_string->size = strlen(initial);
        new_string->data = strdup(initial);
    }
    return new_string;
}

char* get_data(String *s){
    return s->data;
}

void free_string(String *s) {
    assert (s != NULL);
    FREE(s->data);  /* free memory held by the structure */
    FREE(s);        /* free the structure itself */
}
