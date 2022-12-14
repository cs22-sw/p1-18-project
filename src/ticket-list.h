#ifndef TICKET_LIST_H
#define TICKET_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#include "match.h"

typedef struct {
    Match match;
    char attendee[STRING_MAX_LENGTH];
} Ticket;

typedef struct {
    int capacity;
    int length;
    Ticket *data;
} TicketList;

TicketList new_ticket_list(void);

void add_ticket_list(Ticket ticket, TicketList *list);

#endif
