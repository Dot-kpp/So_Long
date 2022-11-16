#include "../include/so_long.h"

void input_error(void)
{
    write(1, "Error\n: Please enter a valid input: ./so_long map.ber\n", 54);
    exit (1);
}

void map_error(void)
{
    write(1, "Error\n: The map in invalid!\n", 28);
    exit (1);
}

void map_error_valid_path(void)
{
    write(1, "Error\n: The map does not have a valid win!\n", 43);
    exit (1);
}

void input_error_map_path(void)
{
    write(1, "Error\n: Please enter a valid path to your map\n", 45);
    exit (1);
}

void input_error_invalid_map(void)
{
    write(1, "Error\n: Invalid map\n", 20);
    exit (1);
}