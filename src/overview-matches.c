#include "overview-matches.h"

void overview_of_upcoming_matches(MatchList all_matches)
{
    for (int i = 0; i < all_matches.used_size_arr; i++)
    {
        printf("%d. \t %s\t-\t%s at %s, %d.%d %d/%d-%d \n",
               i,
               all_matches.match[i].team_1,
               all_matches.match[i].team_2,
               all_matches.match[i].stadium,
               all_matches.match[i].match_date_info.hour,
               all_matches.match[i].match_date_info.minute,
               all_matches.match[i].match_date_info.day,
               all_matches.match[i].match_date_info.month,
               all_matches.match[i].match_date_info.year);
    }
}
