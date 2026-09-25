#include "vehicle.h"
#include "input_utilities.h"
#include "person.h"
#include <stdio.h>

void print_vehicle(const struct Vehicle *vehicle)
{
    printf("Vehicle(type = \"%s\", brand = \"%s\", license_plate = \"%s\", "
           "owner's name = \"%s\");\n",
           vehicle->type, vehicle->brand, vehicle->license_plate,
           vehicle->owner.name);
}

bool initialize_vehicle_from_user_input(struct Vehicle *vehicle)
{
    printf("Enter the vehicle's brand: ");
    bool is_brand_input_successful =
        read_user_input_into_buffer(vehicle->brand, BRAND_MAX_LENGTH);

    if (!is_brand_input_successful)
    {
        printf("Invalid brand input\n");
        return false;
    }

    printf("Enter the vehicle's license plate: ");
    bool is_license_plate_input_successful = read_user_input_into_buffer(
        vehicle->license_plate, LICENSE_PLATE_MAX_LENGTH);

    if (!is_license_plate_input_successful)
    {
        printf("Invalid license plate input\n");
        return false;
    }

    printf("Enter the vehicle's type: ");
    bool is_type_input_successful =
        read_user_input_into_buffer(vehicle->type, TYPE_MAX_LENGTH);

    if (!is_type_input_successful)
    {
        printf("Invalid type input\n");
        return false;
    }

    printf("Enter vehicle owner's details:\n");
    bool is_owner_input_successful =
        initialize_person_from_user_input(&(vehicle->owner));

    if (!is_owner_input_successful)
    {
        printf("Invalid owner input\n");
        return false;
    }

    return true;
}
