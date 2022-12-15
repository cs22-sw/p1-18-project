#include "search.h"

// levenshtein distance algorithm
// https://en.wikipedia.org/wiki/Levenshtein_distance#Iterative_with_two_matrix_rows
int minimum(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int levenshtein_distance(char *s, char *t) {
    // Variables
    int n = strlen(s);
    int m = strlen(t);
    int arr[n+1][m+1];

    // Catch exceptions
    if (n == 0) return m;
    if (m == 0) return n;
    
    // Initialize
    for (int i = 0; i <= n; i++) {
        arr[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        arr[0][j] = j;
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = (s[i-1] == t[j - 1]) ? 0 : 1;
            arr[i][j] = minimum(arr[i - 1][j] + 1, arr[i][j - 1] + 1, arr[i - 1][j - 1] + cost);
        }
    }
    return arr[n][m];
}

char *find_closest_stadium(MatchList matches, char *search_term) {
    StringList all_stadiums = new_string_list();

    for (int i = 0; i < matches.length; i++) {
        bool stadium_found = false;
        for (int j = 0; j < all_stadiums.length; j++) {
            if (strcmp(all_stadiums.data[j], matches.data[i].stadium) == 0) {
                stadium_found = true;
                break;
            }
        }
        if (!stadium_found) {
            add_string_list(&all_stadiums, matches.data[i].stadium);
        }
    }

    int absolute_distance = 100;
    int closest_word_index = 0;
    for (int i = 0; i < all_stadiums.length; i++) {
        int distance = levenshtein_distance(search_term, all_stadiums.data[i]);
        if (distance <= absolute_distance) {
            absolute_distance = distance;
            closest_word_index = i;
        }
    }

    char* closest_word = malloc(strlen(all_stadiums.data[closest_word_index]) + 1);
    strcpy(closest_word, all_stadiums.data[closest_word_index]);
    free_string_list(all_stadiums);
    return closest_word;
}

char *find_closest_team(MatchList matches, char *search_term) {
    StringList all_teams = new_string_list();
    for (int i = 0; i < matches.length; i++) {
        bool team_1_found = false;
        bool team_2_found = false;
        for (int j = 0; j < all_teams.length; j++) {
            if (strcmp(all_teams.data[j], matches.data[i].team_2) == 0) {
                team_1_found = true;
            }
            if (strcmp(all_teams.data[j], matches.data[i].team_2) == 0) {
                team_2_found = true;
            }
        }
        if (!team_1_found) {
            add_string_list(&all_teams, matches.data[i].team_1);
        }
        if (!team_2_found) {
            add_string_list(&all_teams, matches.data[i].team_2);
        }
    }

    int absolute_distance = 100;
    int closest_word_index = 0;
    for (int i = 0; i < all_teams.length; i++) {
        int distance = levenshtein_distance(search_term, all_teams.data[i]);
        if (distance <= absolute_distance) {
            absolute_distance = distance;
            closest_word_index = i;
        }
    }

    char* closest_word = malloc(strlen(all_teams.data[closest_word_index]) + 1);
    strcpy(closest_word, all_teams.data[closest_word_index]);
    free_string_list(all_teams);
    if (strcmp(search_term, closest_word) != 0) {
        printf("You search word has been changed to the closets word: %s\n", closest_word);
    }
    return closest_word;
}

MatchList search_matches(MatchList Matches, Search_word *search_word) {
    MatchList matches_found = new_match_list();
    char* closest_word;

    if (search_word->operation == team) {
        closest_word = find_closest_team(Matches, search_word->search_word);
        for (int i = 0; i < Matches.length; i++) {
            if (strcmp(closest_word, Matches.data[i].team_1) == 0) {
                add_match_list(Matches.data[i], &matches_found);
            } else if (strcmp(closest_word, Matches.data[i].team_2) == 0) {
                add_match_list(Matches.data[i], &matches_found);
            }
        }
        if (matches_found.length == 0) {
            printf("No matches found.");
        }
    } else if (search_word->operation == stadium) {
        closest_word = find_closest_stadium(Matches, search_word->search_word);
        for (int i = 0; i < Matches.length; i++) {
            if (strcmp(closest_word, Matches.data[i].stadium) == 0) {
                add_match_list(Matches.data[i], &matches_found);
            }
        }
        if (matches_found.length == 0) {
            printf("No matches found.");
        }
    } else if (search_word->operation == date) {
        for (int i = 0; i < Matches.length; i++) {
            if (Matches.data[i].match_date_info.month == search_word->user_input.month && Matches.data[i].match_date_info.day == search_word->user_input.day) {
                add_match_list(Matches.data[i], &matches_found);
            }
        }
    }

    return matches_found;
}
