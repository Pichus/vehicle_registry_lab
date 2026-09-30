#include "menu/menu.h"
#include "menu/menu_option.h"
#include "menu/operation.h"
#include <stdio.h>

const struct MenuOption menu_options[] = {
    {.operation = QUIT, .description = "Quit", .mutates_registry = false},
    {.operation = ADD_VEHICLE,
     .description = "Add vehicle",
     .mutates_registry = true},
    {.operation = REMOVE_VEHICLE,
     .description = "Remove vehicle",
     .mutates_registry = true},
    {.operation = SORT_REGISTRY,
     .description = "Sort",
     .mutates_registry = true},
    {.operation = SHOW_INFO_FOR_VEHICLE,
     .description = "Info",
     .mutates_registry = false},
    {.operation = SHOW_INFO_FOR_ALL_VEHICLES,
     .description = "Show all",
     .mutates_registry = false},
    {.operation = ADD_RANDOM_VEHICLE,
     .description = "Add random",
     .mutates_registry = true},
    {.operation = SEARCH_FOR_VEHICLE_OWNER,
     .description = "Search",
     .mutates_registry = false}};

const int menu_options_size = sizeof(menu_options) / sizeof(struct MenuOption);

struct MenuOption get_menu_option_by_operation(enum Operation operation)
{
    return menu_options[operation];
}

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
