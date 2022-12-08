#ifndef CREATE_ARRAY_H
#define CREATE_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "create-match-stats.h"

MatchList new_match_list();

void add_match(Matches match, MatchList *list);

bool load_matches_file(MatchList *all_matches);

#endif
