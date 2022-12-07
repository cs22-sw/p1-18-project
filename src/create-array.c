#include "create-array.h"

MatchList create_new_match_list()
{
    MatchList match_list = {.total_size_arr = 0, .used_size_arr = 0, .match = NULL};

    return match_list;
}

void add_match(Matches match, MatchList *list)
{
    if(list->total_size_arr == 0)
    {
        list->match = malloc(sizeof(Matches));

        list->match[0] = match;
        list->total_size_arr = 1;
        list->used_size_arr = 1;
        return;

    }
    if(list->used_size_arr == list->total_size_arr)
    {
        Matches* new_match = malloc(sizeof(Matches)*list->total_size_arr*2);

        for (int i = 0; i < list->used_size_arr; i++)
        {
            new_match[i] = list->match[i];
        }
        list->total_size_arr = list->total_size_arr * 2;

        free(list->match);

        list->match = new_match;
    }

    list->match[list->used_size_arr] = match;
    list->used_size_arr = list->used_size_arr + 1;
}

bool create_array(MatchList *all_matches)
{
    int eof = 0;
    FILE *fp;
    fp = fopen("matches.txt", "r");

    for (int i = 0; eof != EOF; i++)
    {
        Matches match;
        Date date;
        eof = fscanf(fp,
                     "%s%*c %s%*c %s%*c %d%*c %d%*c %d%*c %d%*c %d%*c",
                     match.team_1,
                     match.team_2,
                     match.stadium,
                     &date.year,
                     &date.month,
                     &date.day,
                     &date.hour,
                     &date.minute);
        match.match_date_info = date;

        add_match(match, all_matches);
    }
    fclose(fp);

    return true;
}
