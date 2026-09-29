#ifndef MENU_OPTION_H
#define MENU_OPTION_H

#include "operation.h"
#define MAX_DESCRIPTION_SIZE 50

struct MenuOption
{
    enum Operation operation;
    char description[MAX_DESCRIPTION_SIZE];
};

#endif // MENU_OPTION_H
