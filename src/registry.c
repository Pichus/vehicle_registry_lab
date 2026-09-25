#include "registry.h"
#include "person.h"
#include "vehicle.h"
#include <stdio.h>
#include <string.h>

void initialize_registry_with_default_values(struct Registry *registry)
{
    registry->vehicle_count = 0;
}

void sort_registry_by_owner_name(struct Registry *registry)
{
    for (int i = 0; i < registry->vehicle_count; i++)
    {
        for (int j = 0; j < registry->vehicle_count - 1; j++)
        {
            if (strncmp(registry->vehicles[j].owner.name,
                        registry->vehicles[j + 1].owner.name,
                        MAX_NAME_SIZE) > 0)
            {
                struct Vehicle temp = registry->vehicles[j];
                registry->vehicles[j] = registry->vehicles[j + 1];
                registry->vehicles[j + 1] = temp;
            }
        }
    }
}

bool push_back_vehicle_to_registry(struct Registry *registry,
                                   struct Vehicle vehicle)
{
    if (registry->vehicle_count >= MAX_VEHICLE_REGISTRY_CAPACITY)
    {
        return false;
    }

    registry->vehicles[registry->vehicle_count] = vehicle;
    registry->vehicle_count++;

    return true;
}

void print_registry_contents(struct Registry *registry)
{
    for (int i = 0; i < registry->vehicle_count; i++)
    {
        printf("(%d) ", i);
        print_vehicle(&(registry->vehicles[i]));
    }
}

bool is_registry_full(struct Registry *registry)
{
    return registry->vehicle_count >= MAX_VEHICLE_REGISTRY_CAPACITY;
}

bool is_registry_empty(struct Registry *registry)
{
    return registry->vehicle_count == 0;
}
