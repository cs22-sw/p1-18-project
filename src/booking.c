#include "booking.h"

bool print_ticket(Ticket ticket)
{
    printf("\nAttendee: %s\n", ticket.attendee);
    printf(
        "%s - %s at %s, %d:%d %d/%d-%d \n",
        ticket.match.team_1,
        ticket.match.team_2,
        ticket.match.stadium,
        ticket.match.match_date_info.hour,
        ticket.match.match_date_info.minute,
        ticket.match.match_date_info.day,
        ticket.match.match_date_info.month,
        ticket.match.match_date_info.year
    );
}

bool book_ticket(MatchList matches)
{
    int32_t selected = -1;
    char buffer[STRING_MAX_LENGTH];
    
    MatchList matches_found = new_match_list();

    printf("Which teams would you like to watch?\n");
    printf("> ");
    scanf(" %s", buffer);
    printf("%s\n", buffer);
    
    Date empty;
    Search_word inputs = {.operation = team, .user_input = empty};
    strcpy(inputs.search_word, buffer);
    matches_found = search_matches(matches, &inputs);

    // Prints found matches
    overview_of_upcoming_matches(matches_found);

    // Ask the user what matches they would like to book a ticket for
    printf("Which match would you like to book a ticket for? (");
    for (int i = 0; i < matches_found.length; i++) {
        if(i + 1 == matches_found.length) {
            printf("%d)\n", i);
            break;
        }
        printf("%d, ", i);
    }
    printf("> ");
    scanf(" %d", &selected);
    
    if(selected != -1) {
        Ticket new_ticket;
        char newline;
        //Ask the user for an attendee name for the ticket
        printf("Please enter attendee name\n");
        printf("> ");
        scanf(" %[a-zA-Z ]", new_ticket.attendee);

        new_ticket.match = matches_found.data[selected];

        // Prints the ticket to the terminal
        print_ticket(new_ticket);

        for (int i = 0; i < matches.length; i++)
        {
            if (matches.data[i].id == matches_found.data[selected].id)
            {
                matches.data[i].ticket_count = matches.data[i].ticket_count - 1;
                break;
            }
        }
        
        save_matches_file(matches);
    }
    
    return true;
}
