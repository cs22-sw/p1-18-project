#ifndef CREATE_ARRAY_H
#define CREATE_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "match.h"

typedef struct {
    int capacity;
    int length;
    Match *data;
} MatchList;

MatchList new_match_list(void);

void add_match_list(Match match, MatchList *list);

bool load_matches_file(MatchList *all_matches);

#endif
