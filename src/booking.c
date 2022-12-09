#include "booking.h"

bool book_ticket(MatchList matches)
{
    char buffer[STRING_MAX_LENGTH];

    MatchList matches_found = new_match_list();

    printf("Which teams would you like to watch?\n");
    printf("> ");
    scanf(" %s", buffer);

    char* closest_team = find_closest_team(matches, buffer);
    strcpy(buffer, closest_team);
    free(closest_team);

    printf("%s\n", buffer);

    matches_found = search_matches(matches, buffer);

    overview_of_upcoming_matches(matches_found);
    return true;
}
