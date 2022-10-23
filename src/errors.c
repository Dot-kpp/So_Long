#include "../include/so_long.h"

void input_error(void)
{
    write(1, "Please enter a valid input: ./so_long map.ber\n", 47);
    exit (1);
}