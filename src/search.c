#include "search.h"

// levenshtein distance algorithm
// https://en.wikipedia.org/wiki/Levenshtein_distance#Iterative_with_two_matrix_rows
int levenshtein_distance(char *s, char *t) {
    int m = strlen(s);
    int n = strlen(t);
    int v0[n + 1];
    int v1[n + 1];

    for (int i = 0; i < n; i++) {
        v0[i] = i;
    }

    for (int i = 0; i < m; i++) {
        v0[0] = i + 1;

        for (int j = 0; j < n; j++) {
            int deletion_cost = v0[j + 1] + 1;
            int insertion_cost = v1[j] + 1;
            int substitution_cost = 0;

            if (s[i] == t[j]) {
                substitution_cost = v0[j];
            }
            else {
                substitution_cost = v0[j] + 1;
            }

            int minimum = deletion_cost <= insertion_cost ? deletion_cost : insertion_cost;
            v1[j + 1] = substitution_cost <= minimum ? substitution_cost : minimum;
        }
        // swaps the arrays
        for (int k = 0; k < n + 1; k++) {
            int temp;
            temp = v1[k];
            v1[k] = v0[k];
            v0[k] = temp;
        }
    }
    return v0[n];
}

char *find_closest_stadium(MatchList matches, char *search_term)
{
    StringList all_stadiums = new_string_list();

    for (int i = 0; i < matches.length; i++)
    {
        bool stadium_found = false;
        for (int j = 0; j < all_stadiums.length; j++)
        {
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
    for (int i = 0; i < all_stadiums.length; i++)
    {
        int distance = levenshtein_distance(search_term, all_stadiums.data[i]);
        if (distance <= absolute_distance) 
        {
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
        for (int j = 0; all_teams.length; j++) {
            if (strcmp(all_teams.data[j], matches.data[i].team_2) == 0) {
                team_1_found = true;
                break;
            }
            if (strcmp(all_teams.data[j], matches.data[i].team_2) == 0) {
                team_2_found = true;
                break;
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
    return closest_word;
}

MatchList search_matches(MatchList Matches, Search_word *search_word)
{
    MatchList matches_found = new_match_list();
    char closest_word[STRING_MAX_LENGTH];

    switch (search_word->operation)
    {
    case team:
        for (int i = 0; i < Matches.length; i++)
        {
            if(strcmp(search_word, Matches.data[i].team_1) == 0)
            {
                add_match_list(Matches.data[i], &matches_found);
            }
            else if (strcmp(search_word, Matches.data[i].team_2) == 0)
            {
                add_match_list(Matches.data[i], &matches_found);
            }
        }
        if (matches_found.length == 0)
        {
            printf("No matches found.");
        }
        break;
    case stadium:
        for (int i = 0; i < Matches.length; i++)
        {
            if (strcmp(search_word, Matches.data[i].stadium) == 0)
            {
                add_match_list(Matches.data[i], &matches_found);
            }
        }
        if (matches_found.length == 0)
        {
            printf("No matches found.");
        }
        break;
    case date:
        /* code */
        break;
    default:
        break;
    }

    return matches_found;
}
