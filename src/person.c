#include "person.h"
#include "input_utilities.h"
#include "random_utilities.h"
#include <stdio.h>
#include <string.h>

#define NAME_OPTIONS_AMOUNT 10
#define RANDOM_AGE_LOWER_BOUND 18
#define RANDOM_AGE_UPPER_BOUND 95

bool initialize_person_from_user_input(struct Person *person)
{
    printf("Enter the person's name: ");
    bool is_name_input_successful =
        read_user_input_into_buffer(person->name, MAX_NAME_SIZE);

    if (!is_name_input_successful)
    {
        printf("Invalid name input\n");
        return false;
    }

    printf("Enter the person's age: ");
    bool is_age_input_successful = read_int_input(&(person->age));

    if (!is_age_input_successful)
    {
        printf("Invalid age input\n");
        return false;
    }

    return true;
}

char name_options[NAME_OPTIONS_AMOUNT][MAX_NAME_SIZE] = {
    "John Smith",      "Emily Johnson",  "Michael Brown", "Sarah Wilson",
    "David Miller",    "Anna Anderson",  "James Taylor",  "Olivia Thomas",
    "Daniel Martinez", "Sophia Williams"};

void initialize_person_with_random_values(struct Person *person)
{
    int name_option_index = random_value_in_range(0, NAME_OPTIONS_AMOUNT - 1);

    strncpy(person->name, name_options[name_option_index], MAX_NAME_SIZE);

    person->age =
        random_value_in_range(RANDOM_AGE_LOWER_BOUND, RANDOM_AGE_UPPER_BOUND);
}
