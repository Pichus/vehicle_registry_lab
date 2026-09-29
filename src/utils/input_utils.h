#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <stdbool.h>

bool read_user_input_into_buffer(char *buffer, int buffer_size);

bool parse_int_from_string(char *string, int *result);

bool read_int_input(int *result);

void flush_input_stream(void);

#endif // INPUT_UTILS_H
