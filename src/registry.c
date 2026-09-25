#include "registry.h"
#include "vehicle.h"

void initialize_registry_with_default_values(struct Registry *registry)
{
    registry->vehicle_count = 0;
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
        print_vehicle(&(registry->vehicles[i]));
    }
}

bool is_registry_full(struct Registry *registry)
{
    return registry->vehicle_count >= MAX_VEHICLE_REGISTRY_CAPACITY;
}
