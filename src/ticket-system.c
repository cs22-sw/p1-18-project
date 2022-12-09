#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "overview.h"
#include "match.h"
#include "match-list.h"
#include "booking.h"
#include "search.h"

// This asks the user for an integer in the range of 0..=3 which corresponds to our options in the menu
int32_t user_input(void) {
    int32_t selected = -1;
    while (selected < 0 || selected > 3) {
        printf("Please pick an option and type enter (1, 2, 3): ");
        scanf("%d", &selected);
    }
    return selected;
}

void clear_screen() {
    char operation;
    while (true) {
        printf("Do you want to continue?: Y/N ");
        scanf(" %c", &operation);
        if (operation == 'Y' || operation == 'y') {
            // clear console output
            printf("\033[2J\033[1;1h");
            break;
        }
    }
}

void specific_search_print(MatchList matches_found) {
    overview_of_upcoming_matches(matches_found);
}

void specific_search_input(Search_word *ptr_user_input) {
    int operation = -1;
    char temp_string[256];
    int input_month = -1;
    int input_day = -1;
    Date user_input_date;
    Search_word user_input;
    printf("What would you like to search for?: \n");
    printf("1. Team\n");
    printf("2. Stadium\n");
    printf("3. Date\n");

    while (true) {
        scanf("%d", &operation);
        if (operation > 0 && operation < 4) {
            break;
        }
    }

    if (operation == team) {
        printf("Team to search for: \n");
        scanf("%s", temp_string);
    }
    if (operation == stadium) {
        printf("Stadium to search for: \n");
        scanf("%s", temp_string);
    }
    if (operation == date) {
        while (true) {
            printf("Month: \n");
            scanf("%d", &input_month);
            if (input_month > 0 && input_month < 13) {
                break;
            }
        }
        while (true) {
            printf("Day: \n");
            scanf("%d", &input_day);
            if (input_day > 0 && input_day < 31) {
                break;
            }
        }
        user_input_date = (Date){.month = input_month, .day = input_day};
        ptr_user_input->operation = operation;
        ptr_user_input->user_input = user_input_date;
        return;
    }

    strcpy(ptr_user_input->search_word, temp_string);
    ptr_user_input->operation = operation;
}

int main(void) {
    // Create list
    MatchList all_matches = new_match_list();
    
    // Reads matches.txt and adds the unto the list
    load_matches_file(&all_matches);

    while (true) {
        printf("1. Overview of upcoming matches\n");
        printf("2. Book tickets\n");
        printf("3. Search upcoming matches\n");
        printf("0. Exit\n");
        int32_t selected = user_input();
        Search_word inputs;
        switch (selected) {
        case 0:
            return 0;
        case 1:
            // printf("An overview of upcoming matches and where to get tickets so the users are able to find and purchase tickets for the matches they are interested in. This helps make the whole process easier for the users not only by showing the matches but also by providing a page or a link straight to the specific tickets product page.\n");
            printf("Overview of upcoming matches: \n");
            overview_of_upcoming_matches(all_matches);
            clear_screen();
            break;
        case 2:
            printf("A booking system so the customers won’t have to go to a third-party site for booking the tickets, this would streamline the process and make it easier for the customer to acquire the tickets.\n");
            // Prompt the user for which teams they would like to watch *
            // Make new list with only those matches *
            // Display the matches and ask the user which match they would like to book a ticket for *
            // Print the ticket in terminal and in a file WIP
            bool added_successfully = book_ticket(all_matches);
            if (added_successfully) {
                printf("\nBooked success\n");
            }
            clear_screen();
            break;
        // TODO: New case for showing booked tickets
        case 3:
            // printf("Being able to filter matches based on criteria for the matches the customer wants to watch makes it easier and faster for the customer to navigate, and thus reduces the likelihood of them needing to rely on third-party sites, thereby not solving the actual problem of needing multiple sites in the first place.\n");
            specific_search_input(&inputs);
            specific_search_print(search_matches(all_matches, inputs));
            clear_screen();
            break;
        }
    }
}
