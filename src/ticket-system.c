#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "create-match-stats.h"

// This asks the user for an integer in the range of 0..=3 which corresponds to our options in the menu
int32_t user_input(void) {
    int32_t selected = -1;
    while (selected < 0 || selected > 3) {
        printf("Please pick an option and type enter (1, 2, 3): ");
        scanf("%d", &selected);
    }
    return selected;
}

int main(void) {
    // example of creating team:
    /*
    Date date_match = {.year = 2022, .month = 12, .day = 22, .hour = 15, .minute = 15};
    Matches match = create_match("MC united", "FCB", "Old Trafford", date_match);
    */

    while (true) {
        printf("1. Overview of upcoming matches\n");
        printf("2. Book tickets\n");
        printf("3. Search upcoming matches\n");
        printf("0. Exit\n");
        int32_t selected = user_input();
        switch (selected) {
            case 0:
                return 0;
            case 1:
                printf("An overview of upcoming matches and where to get tickets so the users are able to find and purchase tickets for the matches they are interested in. This helps make the whole process easier for the users not only by showing the matches but also by providing a page or a link straight to the specific tickets product page.\n");
                break;
            case 2:
                printf("A booking system so the customers won’t have to go to a third-party site for booking the tickets, this would streamline the process and make it easier for the customer to acquire the tickets.\n");
                break;
            case 3:
                printf("Being able to filter matches based on criteria for the matches the customer wants to watch makes it easier and faster for the customer to navigate, and thus reduces the likelihood of them needing to rely on third-party sites, thereby not solving the actual problem of needing multiple sites in the first place.\n");
                break;
        }
    }
}
