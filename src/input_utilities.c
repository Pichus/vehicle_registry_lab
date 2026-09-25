#include "input_utilities.h"
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_NUMERICAL_BASE 10
#define MAX_USER_INPUT_BUFFER_SIZE 101

// https://post.bytes.com/forum/topic/c/647172-checking-for-excessive-input-when-using-fgets#post4309375
void flush_input_stream(void)
{
    int character;

    do
    {
        character = getchar();
    } while ((character != EOF) && (character != '\n'));

    clearerr(stdin);
}

bool read_user_input_into_buffer(char *buffer, int buffer_size)
{
    if (fgets(buffer, buffer_size, stdin) == NULL)
    {
        return false;
    }

    int newline_char_index = strcspn(buffer, "\n");

    bool is_newline_char_found = newline_char_index != buffer_size - 1;

    if (!is_newline_char_found)
    {
        flush_input_stream();
    }

    buffer[strcspn(buffer, "\n")] = '\0';

    return true;
}

bool parse_int_from_string(char *string, int *result)
{
    char *end_ptr;

    errno = 0;
    long parsed_input = strtol(string, &end_ptr, INPUT_NUMERICAL_BASE);

    bool input_out_of_long_type_range = errno == ERANGE;
    bool no_digits_found = end_ptr == string;
    bool found_further_chars_after_number =
        *end_ptr != '\0' && *end_ptr != '\n';
    bool value_out_of_int_bounds =
        parsed_input < INT_MIN || parsed_input > INT_MAX;

    if (input_out_of_long_type_range || no_digits_found ||
        found_further_chars_after_number || value_out_of_int_bounds)
    {
        return false;
    }

    *result = parsed_input;

    return true;
}

bool read_int_input(int *result)
{
    char input_buffer[MAX_USER_INPUT_BUFFER_SIZE];
    bool is_input_read_successful =
        read_user_input_into_buffer(input_buffer, MAX_USER_INPUT_BUFFER_SIZE);

    if (!is_input_read_successful)
    {
        return false;
    }

    int parsed_value;
    bool is_int_parsing_successful =
        parse_int_from_string(input_buffer, &parsed_value);

    if (!is_int_parsing_successful)
    {
        return false;
    }

    *result = parsed_value;

    return true;
}
