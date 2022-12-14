#include "ticket-list.h"

TicketList new_ticket_list(void) {
    TicketList ticket_list = {.capacity = 0, .length = 0, .data = NULL};
    return ticket_list;
}

void add_ticket_list(Ticket ticket, TicketList *list) {
    if(list->capacity == 0) {
        list->data = malloc(sizeof(Ticket));

        list->data[0] = ticket;
        list->capacity = 1;
        list->length = 1;
        return;
    }

    if(list->length == list->capacity) {
        Ticket* new_ticket = malloc(sizeof(Ticket) * list->capacity * 2);

        for (int i = 0; i < list->length; i++) {
            new_ticket[i] = list->data[i];
        }
        list->capacity = list->capacity * 2;
        free(list->data);
        list->data = new_ticket;
    }

    list->data[list->length] = ticket;
    list->length = list->length + 1;
}
