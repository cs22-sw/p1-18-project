#include "overview-matches.h"

void overview_of_upcoming_matches(Matches *array_matches, int size_array_matches) {
    for (int i = 0; i < size_array_matches; i++) {
        printf("%d. \t %s\t-\t%s at %s, %d.%d %d/%d-%d \n",
               i,
               array_matches[i].team_1,
               array_matches[i].team_2,
               array_matches[i].stadium,
               array_matches[i].match_date_info.hour,
               array_matches[i].match_date_info.minute,
               array_matches[i].match_date_info.day,
               array_matches[i].match_date_info.month,
               array_matches[i].match_date_info.year);
    }
}
