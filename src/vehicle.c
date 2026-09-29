#include "vehicle.h"
#include "person.h"
#include "utils/input_utils.h"
#include "utils/random_utils.h"
#include <stdio.h>
#include <string.h>

#define AMOUNT_OF_OPTIONS 10

const char type_options[AMOUNT_OF_OPTIONS][TYPE_MAX_LENGTH] = {
    "Sedan", "SUV",     "Hatchback", "Coupe", "Convertible",
    "Wagon", "Minivan", "Pickup",    "Van",   "Motorcycle"};

const char brand_options[AMOUNT_OF_OPTIONS][BRAND_MAX_LENGTH] = {
    "Volvo", "Toyota", "BMW",        "Mercedes-Benz", "Audi",
    "Ford",  "Honda",  "Volkswagen", "Hyundai",       "Nissan"};

const char license_plate_options[AMOUNT_OF_OPTIONS][LICENSE_PLATE_MAX_LENGTH] =
    {"ABC123", "XYZ789", "KLM456", "DEF321", "GHI654",
     "JKL987", "MNO246", "PQR135", "STU864", "VWX579"};

void initialize_vehicle_with_random_values(struct Vehicle *vehicle)
{
    int type_option_index = random_value_in_range(0, AMOUNT_OF_OPTIONS - 1);
    int brand_option_index = random_value_in_range(0, AMOUNT_OF_OPTIONS - 1);
    int license_plate_option_index =
        random_value_in_range(0, AMOUNT_OF_OPTIONS - 1);

    strncpy(vehicle->type, type_options[type_option_index], TYPE_MAX_LENGTH);
    strncpy(vehicle->brand, brand_options[brand_option_index],
            BRAND_MAX_LENGTH);
    strncpy(vehicle->license_plate,
            license_plate_options[license_plate_option_index],
            LICENSE_PLATE_MAX_LENGTH);

    initialize_person_with_random_values(&(vehicle->owner));
}

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
