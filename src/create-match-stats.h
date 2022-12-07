#ifndef CREATE_MATCH_STATS_H
#define CREATE_MATCH_STATS_H

#include <string.h>

#define STRING_MAX_LENGTH 256

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
} Date;

typedef struct {
    char team_1[STRING_MAX_LENGTH];
    char team_2[STRING_MAX_LENGTH];
    char stadium[STRING_MAX_LENGTH];
    Date match_date_info;
} Matches;

typedef struct {
    int total_size_arr;
    int used_size_arr;
    Matches *match;
} MatchList;

Matches create_match(char *first_team,
                     char *second_team,
                     char *stadium_match,
                     Date info_date_match);

#endif
