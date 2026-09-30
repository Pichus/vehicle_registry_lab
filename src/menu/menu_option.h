#ifndef MENU_OPTION_H
#define MENU_OPTION_H

#include "menu/operation.h"
#include <stdbool.h>
#define MAX_DESCRIPTION_SIZE 50

struct MenuOption
{
    enum Operation operation;
    char description[MAX_DESCRIPTION_SIZE];
    bool mutates_registry;
};

#endif // MENU_OPTION_H
