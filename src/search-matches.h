#ifndef SEARCH_MATCHES_H
#define SEARCH_MATCHES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "create-match-stats.h"
#include "create-array.h"
#include "string-list.h"

MatchList search_matches(MatchList Matches, char *search_word);

char *check_levenshtein_distance(MatchList matches, char *search_stirng);

int levenshtein_distance(char *string_1, char *string_2);

#endif
