#ifndef PERSON_H
#define PERSON_H

#include <stdbool.h>
#define MAX_NAME_SIZE 21

struct Person
{
    char name[MAX_NAME_SIZE];
    int age;
};

bool initialize_person_from_user_input(struct Person *person);

#endif // PERSON_H
