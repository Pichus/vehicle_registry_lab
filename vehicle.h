#ifndef VEHICLE_H
#define VEHICLE_H

#include "person.h"

struct Vehicle
{
    char *type;
    char *brand;
    char *license_plate;
    Person owner;
};

#endif // VEHICLE_H
