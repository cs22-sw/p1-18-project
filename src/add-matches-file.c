#include "add-matches-file.h"

bool add_array_matches(Matches *all_matches, int size_all_matches) {
    for (int i = 0; i < size_all_matches; i++) {
        bool temp = add_match_txt_file(all_matches[i]);
        if (!temp) {
            return false;
        }
    }
    return true;
}

bool add_match_txt_file(Matches match) {
    char *file_name = "../src/matches.txt";
    FILE *fp = fopen(file_name, "a");

    if (fp == NULL) {
        printf("Error opening the text file");
        fclose(fp);
        return false;
    }

    fprintf(fp, "%s,%s,%s,%d,%d,%d,%d,%d\n",
            match.team_1,
            match.team_2,
            match.stadium,
            match.match_date_info.hour,
            match.match_date_info.minute,
            match.match_date_info.day,
            match.match_date_info.month,
            match.match_date_info.year);

    fclose(fp);
    return true;
}
