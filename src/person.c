#include "person.h"
#include "input_utilities.h"
#include <stdio.h>

bool initialize_person_from_user_input(struct Person *person)
{
    printf("Enter the person's name: ");
    bool is_name_input_successful =
        read_user_input_into_buffer(person->name, MAX_NAME_SIZE);

    if (!is_name_input_successful)
    {
        return false;
    }

    printf("Enter the person's age: ");
    bool is_age_input_successful = read_int_input(&(person->age));

    return is_age_input_successful;
}
