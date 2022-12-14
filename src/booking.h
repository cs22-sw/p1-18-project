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
#include "ticket-list.h"

#define STRING_MAX_LENGTH 256

bool save_ticket(TicketList tickets);

bool read_tickets_file(TicketList *tickets);

bool print_ticket(TicketList tickets);

bool book_ticket(MatchList matches);


#endif
