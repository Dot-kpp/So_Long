#include "../include/so_long.h"

void move_up(t_data *data);

void move_down(t_data *data);

void move_left(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < data->w - 1)
    {
        j = 0;
        while (data->map [i][j] != '\n')
        {
            if (data->map[i][j] != 'P' && data->map[i][j - 1] != '1' && data->map[i][j - 1] != 'E')
            {
                
            }
        }

    }

}

void move_right(t_data *data);

void move_exit(t_data *data);

