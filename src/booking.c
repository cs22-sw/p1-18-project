#include "booking.h"

bool print_ticket(Ticket ticket)
{
    printf("\nAtendee: %s\n", ticket.atendee);
    printf("%s - %s at %s, %d:%d %d/%d-%d \n",
            ticket.match.team_1,
            ticket.match.team_2,
            ticket.match.stadium,
            ticket.match.match_date_info.hour,
            ticket.match.match_date_info.minute,
            ticket.match.match_date_info.day,
            ticket.match.match_date_info.month,
            ticket.match.match_date_info.year);
}

bool book_ticket(MatchList matches)
{
    int32_t selected = -1;
    char *buffer = calloc(256, sizeof(char));

    MatchList matches_found = new_match_list();

    printf("Which teams would you like to watch?\n");
    printf("> ");
    scanf(" %s", buffer);

    char* closest_team = check_levenshtein_distance(matches, buffer);
    strcpy(buffer, closest_team);
    free(closest_team);

    printf("%s\n", buffer);

    if (buffer != NULL)
    {
        matches_found = search_matches(matches, buffer);
    }

    // Prints found matches
    overview_of_upcoming_matches(matches_found);

    // Ask the user what matches they would like to book a ticket for
    printf("Which match would you like to book a ticket for? (");
    for (int i = 0; i < matches_found.used_size_arr; i++)
    {
        if(i + 1 == matches_found.used_size_arr)
        {
            printf("%d)\n", i);
            break;
        }
        printf("%d, ", i);
    }
    printf("> ");
    scanf(" %d", &selected);
    
    if(selected != -1)
    {
        Ticket new_ticket;
        char newline;
        //Askes the user for an atendee name for the ticket
        printf("Please enter atendee name\n");
        printf("> ");
        scanf(" %[a-zA-Z ]", new_ticket.atendee);

        new_ticket.match = matches_found.match[selected];

        // Prints the ticket to the terminal
        print_ticket(new_ticket);

        free(buffer);
    }


    return true;
}
