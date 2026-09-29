#include "menu/operation_handlers.h"
#include "utils/input_utils.h"
#include <stdio.h>

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

bool handle_remove_vehicle_operation(struct Registry *registry)
{
    if (is_registry_empty(registry))
    {
        printf("The registry contains no vehicles.\n");
        return false;
    }

    printf("Enter the position of a vehicle you want to remove: ");

    int vehicle_position_starting_from_1;
    bool is_position_input_successful =
        read_int_input(&vehicle_position_starting_from_1);

    if (!is_position_input_successful)
    {
        printf("Invalid vehicle position input\n");
        return false;
    }

    bool is_vehicle_position_valid =
        vehicle_position_starting_from_1 >= 1 &&
        vehicle_position_starting_from_1 <= registry->vehicle_count;

    if (!is_vehicle_position_valid)
    {
        printf("There's no car with number %d in the registry\n",
               vehicle_position_starting_from_1);
        return false;
    }

    int vehicle_position_starting_from_0 = vehicle_position_starting_from_1 - 1;

    bool is_vehicle_removal_successful = remove_vehicle_from_registry(
        registry, vehicle_position_starting_from_0);

    if (!is_vehicle_removal_successful)
    {
        printf("Couldn't remove the vehicle from the registry\n");
        return false;
    }

    return true;
}

bool handle_sort_registry_operation(struct Registry *registry)
{
    if (is_registry_empty(registry) || is_registry_sorted(registry))
    {
        return true;
    }

    sort_registry_by_owner_name(registry);

    return true;
}

bool handle_show_info_for_vehicle_operation(struct Registry *registry)
{
    if (is_registry_empty(registry))
    {
        printf("The registry contains no vehicles.\n");
        return false;
    }

    printf("Enter the position of a vehicle you want to get info about: ");

    int vehicle_position_starting_from_1;
    bool is_position_input_successful =
        read_int_input(&vehicle_position_starting_from_1);

    if (!is_position_input_successful)
    {
        printf("Invalid vehicle position input\n");
        return false;
    }

    bool is_vehicle_position_valid =
        vehicle_position_starting_from_1 >= 1 &&
        vehicle_position_starting_from_1 <= registry->vehicle_count;

    if (!is_vehicle_position_valid)
    {
        printf("There's no car with number %d in the registry\n",
               vehicle_position_starting_from_1);
        return false;
    }

    int vehicle_position_starting_from_0 = vehicle_position_starting_from_1 - 1;

    print_vehicle(&(registry->vehicles[vehicle_position_starting_from_0]));

    return true;
}

bool handle_add_random_vehicle_operation(struct Registry *registry)
{
    if (is_registry_full(registry))
    {
        printf("Vehicle registry is already full\n");
        return false;
    }

    struct Vehicle vehicle;
    initialize_vehicle_with_random_values(&vehicle);

    bool is_push_back_successful =
        push_back_vehicle_to_registry(registry, vehicle);

    if (!is_push_back_successful)
    {
        printf("Vehicle registry is already full\n");
    }

    return is_push_back_successful;
}

bool handle_search_for_vehicle_owner_operation(struct Registry *registry)
{
    if (is_registry_empty(registry))
    {
        printf("Can't search through an empty registry.\n");
        return false;
    }

    if (!is_registry_sorted(registry))
    {
        printf("Before performing a search operation, the registry must be "
               "sorted.\n");
        return false;
    }

    char owner_name[MAX_NAME_SIZE];
    bool is_name_input_successfull =
        read_user_input_into_buffer(owner_name, MAX_NAME_SIZE);

    if (!is_name_input_successfull)
    {
        printf("Invalid input.\n");
        return false;
    }

    int target_vehicle_index =
        find_vehicle_index_by_owner_name(registry, owner_name);

    bool is_vehicle_found = target_vehicle_index != -1;

    if (!is_vehicle_found)
    {
        printf("Vehicle not found.\n");
        return false;
    }

    struct Vehicle vehicle = registry->vehicles[target_vehicle_index];

    print_vehicle(&vehicle);

    return true;
}
