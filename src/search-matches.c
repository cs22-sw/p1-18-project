#include "search-matches.h"

// levenshtein distance algorithm
int levenshtein_distance(char *string_1, char *string_2) {
    int string_1_length = strlen(string_1);
    int string_2_length = strlen(string_2);
    int vector_1[string_2_length + 1];
    int vector_2[string_2_length + 1];

    for (int i = 0; i < string_2_length; i++) {
        vector_1[i] = i;
    }

    for (int i = 0; i < string_1_length; i++) {
        vector_1[0] = i + 1;

        for (int j = 0; j < string_2_length; j++) {
            int delete_cost = vector_1[j + 1] + 1;
            int insert_cost = vector_2[j] + 1;
            int substitution_cost = 0;
            int temp;

            if (string_1[i] == string_2[j]) {
                substitution_cost = vector_1[j];
            }
            else {
                substitution_cost = vector_1[j] + 1;
            }
            temp = (delete_cost <= insert_cost ? delete_cost : insert_cost);
            vector_2[j + 1] = (substitution_cost <= temp ? substitution_cost : temp);
        }
        // swaps the arrays
        for (int n = 0; n < string_2_length + 1; n++) {
            int temp;
            temp = vector_2[n];
            vector_2[n] = vector_1[n];
            vector_1[n] = temp;
        }
    }
    return vector_1[string_2_length];
}

char *check_levenshtein_distance(MatchList matches, char *search_stirng) {
    StringList all_teams = new_string_list();
    for (int i = 0; i < matches.used_size_arr; i++) {
        char team_1[STRING_MAX_LENGTH];
        char team_2[STRING_MAX_LENGTH];
        
        strcpy(team_1, matches.match[i].team_1);
        strcpy(team_2, matches.match[i].team_2);

        bool team_1_found = false;
        bool team_2_found = false;
        for (int j = 0; all_teams.length; j++) {
            if (strcmp(all_teams.data[j], matches.match[i].team_2) == 0) {
                team_1_found = true;
                break;
            }
            if (strcmp(all_teams.data[j], matches.match[i].team_2) == 0) {
                team_2_found = true;
                break;
            }
        }
        if (!team_1_found) {
            add_string_list(&all_teams, matches.match[i].team_1);
        }
        if (!team_2_found) {
            add_string_list(&all_teams, matches.match[i].team_2);
        }
    }

    int absolute_distance = 100;
    char close_search_word[STRING_MAX_LENGTH];
    for (int i = 0; i < all_teams.length; i++) {
        int distance = levenshtein_distance(search_stirng, all_teams.data[i]);
        if (distance <= absolute_distance) {
            absolute_distance = distance;
            strcpy(close_search_word, all_teams.data[i]);
        }
    }

    char* closest_word = malloc(strlen(close_search_word) + 1);
    strcpy(closest_word, close_search_word);
    free_string_list(all_teams);
    return closest_word;
}

MatchList search_matches(MatchList Matches, char *search_word)
{
    MatchList matches_found = new_match_list();

    for (int i = 0; i < Matches.used_size_arr; i++)
    {
        if(strcmp(search_word, Matches.match[i].team_1) == 0)
        {
            add_match(Matches.match[i], &matches_found);
        }
        else if (strcmp(search_word, Matches.match[i].team_2) == 0)
        {
            add_match(Matches.match[i], &matches_found);
        }
    }

    return matches_found;
}
