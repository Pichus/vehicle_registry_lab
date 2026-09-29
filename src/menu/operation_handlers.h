#ifndef OPERATION_HANDLERS_H
#define OPERATION_HANDLERS_H

#include "entities/registry.h"
#include <stdbool.h>

bool handle_add_vehicle_operation(struct Registry *registry);

bool handle_remove_vehicle_operation(struct Registry *registry);

bool handle_sort_registry_operation(struct Registry *registry);

bool handle_show_info_for_vehicle_operation(struct Registry *registry);

bool handle_add_random_vehicle_operation(struct Registry *registry);

bool handle_search_for_vehicle_owner_operation(struct Registry *registry);

#endif // OPERATION_HANDLERS_H
