#ifndef BOOKING_H
#define BOOKING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "create-match-stats.h"
#include "create-array.h"
#include "search-matches.h"
#include "overview-matches.h"

#define STRING_MAX_LENGTH 256

typedef struct {
    Matches match;
    char atendee[STRING_MAX_LENGTH];
} Ticket;

bool print_ticket(Ticket ticket);

bool book_ticket(MatchList matches);


#endif
