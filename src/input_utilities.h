#ifndef SAFE_INPUT_H
#define SAFE_INPUT_H

#include <stdbool.h>

bool read_user_input_into_buffer(char *buffer, int buffer_size);

bool parse_int_from_string(char *string, int *result);

bool read_int_input(int *result);

#endif // SAFE_INPUT_H
