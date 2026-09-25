#include "menu.h"
#include "menu_option.h"
#include "operation.h"
#include <stdio.h>

const struct MenuOption menu_options[] = {
    {.operation = ADD_VEHICLE, .description = "Add vehicle"},
    {.operation = REMOVE_VEHICLE, .description = "Remove vehicle"},
    {.operation = SORT_REGISTRY, .description = "Sort"},
    {.operation = SHOW_INFO_FOR_VEHICLE, .description = "Info"},
    {.operation = SHOW_INFO_FOR_ALL_VEHICLES, .description = "Show all"},
    {.operation = ADD_RANDOM_VEHICLE, .description = "Add random"},
    {.operation = SEARCH_FOR_VEHICLE_OWNER, .description = "Search"},
    {.operation = QUIT, .description = "Quit"}};

const int menu_options_size = sizeof(menu_options) / sizeof(struct MenuOption);

void display_menu(void)
{
    for (int i = 0; i < menu_options_size; i++)
    {
        printf("%d. %s\n", menu_options[i].operation,
               menu_options[i].description);
    }
}

bool is_menu_option_choice_valid(int menu_option_choice)
{
    return menu_option_choice >= OPERATION_SELECTION_LOWER_BOUND &&
           menu_option_choice <= OPERATION_SELECTION_UPPER_BOUND;
}
