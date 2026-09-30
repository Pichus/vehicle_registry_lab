#ifndef MENU_H
#define MENU_H

#include "menu/operation.h"
#include <stdbool.h>

void display_menu(void);

bool is_menu_option_choice_valid(int menu_option_choice);

struct MenuOption get_menu_option_by_operation(enum Operation operation);

#endif // MENU_H
