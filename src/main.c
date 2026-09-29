#include "entities/registry.h"
#include "menu/menu.h"
#include "menu/operation.h"
#include "menu/operation_handlers.h"
#include "utils/input_utils.h"
#include "utils/random_utils.h"
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool perform_operation_on_registry(struct Registry *registry,
                                   enum Operation operation)
{
    bool result = true;

    switch (operation)
    {
    case ADD_VEHICLE:
        result = handle_add_vehicle_operation(registry);
        break;
    case REMOVE_VEHICLE:
        result = handle_remove_vehicle_operation(registry);
        break;
    case SORT_REGISTRY:
        result = handle_sort_registry_operation(registry);
        break;
    case SHOW_INFO_FOR_VEHICLE:
        result = handle_show_info_for_vehicle_operation(registry);
        break;
    case SHOW_INFO_FOR_ALL_VEHICLES:
        print_registry_contents(registry);
        break;
    case ADD_RANDOM_VEHICLE:
        result = handle_add_random_vehicle_operation(registry);
        break;
    case SEARCH_FOR_VEHICLE_OWNER:
        result = handle_search_for_vehicle_owner_operation(registry);
        break;
    default:
        break;
    }

    return result;
}

void run_main_loop(void)
{
    struct Registry registry;
    initialize_registry_with_default_values(&registry);

    bool running = true;
    while (running)
    {
        display_menu();
        int user_input;
        bool read_user_input_successfully = read_int_input(&user_input);

        if (!read_user_input_successfully)
        {
            printf("Invalid input\n");
            continue;
        }

        if (!is_menu_option_choice_valid(user_input))
        {
            printf(
                "Invalid menu choice: the choice must be in range [%d, %d]\n",
                OPERATION_SELECTION_LOWER_BOUND,
                OPERATION_SELECTION_UPPER_BOUND);
            continue;
        }

        enum Operation next_operation = user_input;

        perform_operation_on_registry(&registry, next_operation);

        if (next_operation == QUIT)
        {
            running = false;
        }
    }
}

int main(void)
{
    set_random_seed();
    run_main_loop();
    return 0;
}
