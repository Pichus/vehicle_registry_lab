#ifndef VEHICLE_H
#define VEHICLE_H

#include "person.h"
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

#endif // VEHICLE_H
