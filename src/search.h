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

#define STRING_MAX_LENGTH 256

typedef enum {
    team = 1,
    stadium = 2,
    date = 3
} Search_Options;

typedef struct {
    Date user_input;
    int operation;
    char search_word[STRING_MAX_LENGTH];
} Search_word;

int levenshtein_distance(char *s, char *t);

char *find_closest_stadium(MatchList matches, char *search_term);

char *find_closest_team(MatchList matches, char *search_team);

MatchList search_matches(MatchList Matches, Search_word *search_word);

#endif
