#ifndef SEARCH_MATCHES_H
#define SEARCH_MATCHES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "match.h"
#include "match-list.h"
#include "string-list.h"

typedef enum {
    team = 1,
    stadium = 2,
    date = 3
} Search_Options;

typedef struct {
    Date user_input;
    int operation;
    char *search_word;
} Search_word;

MatchList search_matches(MatchList Matches, Search_word inputs);

char *find_closest_team(MatchList matches, char *search_team);

int levenshtein_distance(char *s, char *t);

#endif
