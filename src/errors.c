#include "../include/so_long.h"

void input_error(void)
{
    write(1, "Error\n: Please enter a valid input: ./so_long map.ber\n", 54);
    exit (1);
}