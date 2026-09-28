#include "random_utilities.h"
#include <stdlib.h>
#include <time.h>

void set_random_seed(void)
{
    srand(time(NULL));
}

int random_value_in_range(int range_lower_bound, int range_upper_bound)
{
    return range_lower_bound +
           (rand() % (range_upper_bound - range_lower_bound + 1));
}
