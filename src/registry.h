#ifndef REGISTRY_H
#define REGISTRY_H

#include "vehicle.h"
#include <stdbool.h>
#define MAX_VEHICLE_REGISTRY_CAPACITY 10

struct Registry
{
    struct Vehicle vehicles[MAX_VEHICLE_REGISTRY_CAPACITY];
    int vehicle_count;
};

void initialize_registry_with_default_values(struct Registry *registry);

void persist_registry(struct Registry registry);

bool push_back_vehicle_to_registry(struct Registry *registry,
                                   struct Vehicle vehicle);

void remove_vehicle_from_registry(struct Registry *registry,
                                  int vehicle_position);

struct Vehicle *find_vehicle_by_owner_name(char *owner_name);

void sort_registry(struct Registry *registry);

void print_registry_contents(struct Registry *registry);

bool is_registry_full(struct Registry *registry);

#endif // REGISTRY_H
