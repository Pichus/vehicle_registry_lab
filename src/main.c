#include "menu_option.h"
#include "operation.h"
#include "person.h"
#include "vehicle.h"
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define OPERATION_SELECTION_LOWER_BOUND 0
#define OPERATION_SELECTION_UPPER_BOUND 7
#define MAX_USER_INPUT_BUFFER_SIZE 101
#define INPUT_NUMERICAL_BASE 10

void display_menu(struct MenuOption menu_options[], int menu_options_size)
{
    for (int i = 0; i < menu_options_size; i++)
    {
        printf("%d. %s\n", menu_options[i].operation, menu_options[i].description);
    }
}

bool is_menu_option_choice_valid(long menu_option_choice)
{
    return menu_option_choice >= OPERATION_SELECTION_LOWER_BOUND &&
           menu_option_choice <= OPERATION_SELECTION_UPPER_BOUND;
}

bool read_user_input(long *user_input)
{

    char user_input_buffer[MAX_USER_INPUT_BUFFER_SIZE];
    if (fgets(user_input_buffer, MAX_USER_INPUT_BUFFER_SIZE, stdin) == NULL)
    {
        return false;
    }

    char *end_ptr;

    errno = 0;
    long parsed_input = strtol(user_input_buffer, &end_ptr, INPUT_NUMERICAL_BASE);

    bool input_out_of_long_type_range = errno == ERANGE;
    bool no_digits_found = end_ptr == user_input_buffer;
    bool found_further_chars_after_number = *end_ptr != '\0' && *end_ptr != '\n';
    if (input_out_of_long_type_range || no_digits_found || found_further_chars_after_number)
    {
        return false;
    }

    *user_input = parsed_input;

    return true;
}

void run_main_loop()
{
    struct MenuOption menu_options[] = {{.operation = ADD_VEHICLE, .description = "Add vehicle"},
                                        {.operation = REMOVE_VEHICLE, .description = "Remove vehicle"},
                                        {.operation = SORT_REGISTRY, .description = "Sort"},
                                        {.operation = SHOW_INFO_FOR_VEHICLE, .description = "Info"},
                                        {.operation = SHOW_INFO_FOR_ALL_VEHICLES, .description = "Show all"},
                                        {.operation = ADD_RANDOM_VEHICLE, .description = "Add random"},
                                        {.operation = SEARCH_FOR_VEHICLE_OWNER, .description = "Search"},
                                        {.operation = QUIT, .description = "Quit"}};
    int running = 1;
    while (running)
    {
        display_menu(menu_options, 8);
        long user_input;
        bool read_user_input_successfully = read_user_input(&user_input);

        if (!read_user_input_successfully)
        {
            printf("Invalid input\n");
            continue;
        }

        if (!is_menu_option_choice_valid(user_input))
        {
            printf("Invalid menu choice: the choice must be in range [%d, %d]\n", OPERATION_SELECTION_LOWER_BOUND,
                   OPERATION_SELECTION_UPPER_BOUND);
            continue;
        }

        enum Operation next_operation = user_input;

        if (next_operation == QUIT)
        {
            running = 0;
        }
    }
}

int main()
{
    run_main_loop();
    return 0;
}
