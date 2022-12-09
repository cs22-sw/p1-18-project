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

MatchList search_matches(MatchList Matches, char *search_word);

char *find_closest_team(MatchList matches, char *search_team);

int levenshtein_distance(char *s, char *t);

#endif
