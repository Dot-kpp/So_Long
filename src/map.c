#include "../include/so_long.h"

void get_map_size(t_data *data, char argv[1])
{
    int i;
    int fd;
    char *rows;

    i = 0;
    fd = open(argv, O_RDONLY);
    rows = get_next_line(fd);
    data->h = 0;
    data->w = -1;
    while (rows[i])
    {
        i++;
        data->w++;
    }
    while (rows != NULL)
    {
        free(rows);
        rows = get_next_line(fd);
        data->h++;
    }
    data->height = data->h * 32;
    data->width = data->w * 32;
    free(rows);
    close(fd);
}

void get_map(t_data *data, char *argv)
{
    int i;
    int fd;

char  *temp;

    data = get_data();
    fd = open(argv, O_RDONLY);
    data->map = ft_calloc(data->h + 1, sizeof(char *));
    i = 0;
    while (i <= data->h)
    {
        temp = get_next_line(fd);
        data->map[i] = temp;
        i++;
    }
    data->map[i] = "\0";
    close(fd);
}

void get_player_position(void)
{
    t_data *data;

    int i;
    int j;

    data = get_data();
    j = 0;
    while (j <= data->w)
    {
        i = 0;
        while (i < data->h)
        {
            if (data->map[i][j] == 'P')
            {
                data->pos_x = i;
                data->pos_y = j;
            }
            i++;
        }
        j++;
    }
}

void get_collectable_count(void)
{
    t_data *data;
    int i;
    int j;
    data = get_data();
    j = 0;
    while (j < data->w)
    {
        i = 0;
        while (i < data->h)
        {
            if (data->map[i][j] == 'C')
                data->collectable_count++;
            i++;
        }
        j++;
    }
    data->check_collectable_count = data->collectable_count;
}