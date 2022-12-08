#include "booking.h"

bool book_ticket(MatchList matches)
{
    char *buffer = calloc(256, sizeof(char));

    MatchList matches_found = new_match_list();

    printf("Which teams would you like to watch?\n");
    printf("> ");
    scanf(" %s", buffer);

    strcpy(buffer, check_levenshtein_distance(matches, buffer));

    if(buffer != NULL)
    {
        matches_found = search_matches(matches, buffer);
    }
    
    overview_of_upcoming_matches(matches_found);

    free(buffer);
}
