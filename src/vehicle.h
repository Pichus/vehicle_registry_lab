#ifndef VEHICLE_H
#define VEHICLE_H

#include "person.h"
#include <stdbool.h>
#define LICENSE_PLATE_MAX_LENGTH 101
#define BRAND_MAX_LENGTH 101
#define TYPE_MAX_LENGTH 101

struct Vehicle
{
    char type[TYPE_MAX_LENGTH];
    char brand[BRAND_MAX_LENGTH];
    char license_plate[LICENSE_PLATE_MAX_LENGTH];
    struct Person owner;
};

void print_vehicle(const struct Vehicle *vehicle);

bool initialize_vehicle_from_user_input(struct Vehicle *vehicle);

#endif // VEHICLE_H
