#include "string-list.h"

StringList new_string_list() {
    return (StringList){
        .length = 0,
        .capacity = 0,
        .data = NULL
    };
}

void add_string_list(StringList* list, char* istr) {
    int len = strlen(istr);
    char* str = malloc(len+1);
    strcpy(str, istr);

    if(list->capacity == 0) {
        list->data = malloc(sizeof(char*));

        list->data[0] = str;
        list->capacity = 1;
        list->length = 1;
        return;
    }

    if(list->length == list->capacity) {
        char** new_data = malloc(sizeof(char*) * list->capacity*2);

        for (int i = 0; i < list->length; i++) {
            new_data[i] = list->data[i];
        }
        list->capacity = list->capacity * 2;
        free(list->data);
        list->data = new_data;
    }

    list->data[list->length] = str;
    list->length = list->length + 1;
}

void free_string_list(StringList list) {
    for (int i = 0; i < list.length; i++) {
        free(list.data[i]);
    }
    free(list.data);
}
