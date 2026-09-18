#include "person.h"
#include "vehicle.h"
#include <stdio.h>

int main()
{
    char name[20];
    char type[20];
    char brand[20];
    char plate[20];
    int age;

    printf("enter owner name: ");
    scanf("%s", name);
    printf("enter owner age: ");
    scanf("%d", &age);
    printf("enter car type: ");
    scanf("%s", type);
    printf("enter car brand: ");
    scanf("%s", brand);
    printf("enter car plate: ");
    scanf("%s", plate);

    struct Person owner = {.name = name, .age = age};
    struct Vehicle vehicle = {.type = type, .brand = brand, .license_plate = plate, .owner = owner};

    printf("owner name = %s ; car brand = %s\n", owner.name, vehicle.brand);

    return 0;
}
