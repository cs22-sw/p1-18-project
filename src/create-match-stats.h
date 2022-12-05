#include <string.h>

#define STRING_MAX_LENGTH 256

typedef struct Date {
    int year;
    int month;
    int day;
    int hour;
    int minute;
} Date;

typedef struct Matches {
    char team_1[STRING_MAX_LENGTH];
    char team_2[STRING_MAX_LENGTH];
    char stadium[STRING_MAX_LENGTH];
    struct Date match_date_info;
} Matches;

Matches create_match(char *first_team, 
                    char *second_team, 
                    char *stadium_match, 
                    Date info_date_match
                    ) {
    Matches match;
    strcpy(match.team_1, first_team);
    strcpy(match.team_2, second_team);
    strcpy(match.stadium, stadium_match);
    match.match_date_info = info_date_match;

    return match;
}
