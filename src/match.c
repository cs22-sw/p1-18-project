#include "match.h"

Match new_match(
    char *first_team,
    char *second_team,
    char *stadium_match,
    Date info_date_match
) {
    Match match;
    strcpy(match.team_1, first_team);
    strcpy(match.team_2, second_team);
    strcpy(match.stadium, stadium_match);
    match.match_date_info = info_date_match;
    return match;
}
