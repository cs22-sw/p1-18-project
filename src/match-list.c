#include "match-list.h"

MatchList new_match_list(void) {
    MatchList match_list = {.capacity = 0, .length = 0, .data = NULL};
    return match_list;
}

void add_match_list(Match match, MatchList *list) {
    if(list->capacity == 0) {
        list->data = malloc(sizeof(Match));

        list->data[0] = match;
        list->capacity = 1;
        list->length = 1;
        return;
    }

    if(list->length == list->capacity) {
        Match* new_match = malloc(sizeof(Match) * list->capacity * 2);

        for (int i = 0; i < list->length; i++) {
            new_match[i] = list->data[i];
        }
        list->capacity = list->capacity * 2;
        free(list->data);
        list->data = new_match;
    }

    list->data[list->length] = match;
    list->length = list->length + 1;
}

bool load_matches_file(MatchList *all_matches) {
    FILE *fp;
    fp = fopen("../src/matches.txt", "r");
    if (fp == NULL) {
        printf("Couldn't open matches.txt");
        return false;
    }

    while (true) {
        Match match;

        int eof = fscanf(fp, "%[^,],%[^,],%[^,],%d,%d,%d,%d,%d\n", match.team_1, match.team_2, match.stadium,
                     &match.match_date_info.year, &match.match_date_info.month, &match.match_date_info.day,
                     &match.match_date_info.hour, &match.match_date_info.minute);
        if (eof == EOF) {
            break;
        }

        add_match_list(match, all_matches);
    }
    fclose(fp);
    return true;
}
