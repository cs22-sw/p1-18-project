#ifndef ADD_MATCHES_FILE_H
#define ADD_MATCHES_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "create-match-stats.h"

bool add_array_matches(Matches *all_matches, int size_all_matches);
bool add_match_txt_file(Matches match);

#endif
