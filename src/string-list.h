#ifndef STRING_LIST_H_
#define STRING_LIST_H_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int length;
    int capacity;
    char** data;
} StringList;

StringList new_string_list(void);

void add_string_list(StringList* list, char* str);

void free_string_list(StringList list);

#endif // STRING_LIST_H_
