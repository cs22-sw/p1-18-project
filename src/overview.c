#include "overview.h"

void overview_of_upcoming_matches(MatchList all_matches) {
    if (all_matches.length == 0) {
        printf("No matches found\n");
        return;
    }
    for (int i = 0; i < all_matches.length; i++) {
        printf(
     "%d. %s - %s at %s, %d.%d %d/%d-%d \n",
            i,
            all_matches.data[i].team_1,
            all_matches.data[i].team_2,
            all_matches.data[i].stadium,
            all_matches.data[i].match_date_info.hour,
            all_matches.data[i].match_date_info.minute,
            all_matches.data[i].match_date_info.day,
            all_matches.data[i].match_date_info.month,
            all_matches.data[i].match_date_info.year
        );
    }
}
