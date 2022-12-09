#ifndef BOOKING_H
#define BOOKING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "match.h"
#include "match-list.h"
#include "search.h"
#include "overview.h"

#define STRING_MAX_LENGTH 256

typedef struct {
    Match match;
    char attendee[STRING_MAX_LENGTH];
} Ticket;

bool print_ticket(Ticket ticket);

bool book_ticket(MatchList matches);


#endif
