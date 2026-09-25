#include "input_utilities.h"
#include "menu.h"
#include "operation.h"
#include "registry.h"
#include "vehicle.h"
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool handle_add_vehicle_operation(struct Registry *registry)
{
    if (is_registry_full(registry))
    {
        printf("Vehicle registry is already full\n");
        return false;
    }

    struct Vehicle vehicle;
    bool is_vehicle_initialization_successful =
        initialize_vehicle_from_user_input(&vehicle);

    if (!is_vehicle_initialization_successful)
    {
        return false;
    }

    bool is_push_back_successful =
        push_back_vehicle_to_registry(registry, vehicle);

    if (!is_push_back_successful)
    {
        printf("Vehicle registry is already full\n");
        return false;
    }

    return true;
}

bool perform_operation_on_registry(struct Registry *registry,
                                   enum Operation operation)
{
    bool result = true;

    switch (operation)
    {
    case ADD_VEHICLE:
        result = handle_add_vehicle_operation(registry);
        break;
    case SHOW_INFO_FOR_ALL_VEHICLES:
        print_registry_contents(registry);
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
    run_main_loop();
    return 0;
}
