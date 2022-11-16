#include "../include/so_long.h"
void check_top_bottom_walls(void)
{
    t_data *data;

    int j;

    data = get_data();
    j = 0;
    while (j <= data->w - 1)
    {
        if (data->map[0][j] != '1' || data->map[data->h - 1][j] != '1')
            map_error();
        j++;
    }
}

void check_side_walls(void)
{
    t_data *data;

    int i;

    data = get_data();
    i = 0;
    while (i <= data->h - 1)
    {
        if (data->map[i][0] != '1' || data->map[i][data->w - 1] != '1')
            map_error();
        i++;
    }
}

int parse_for_init(int argc, char *argv)
{
    int count;

    if (open(argv, O_RDONLY) == -1)
        input_error_map_path();
    else if (argc == 2 && argv != NULL)
    {
        count = ft_strlen(argv) - 4;
        if (ft_strncmp(&argv[count], ".ber", 4) != 0)
            input_error();
        else
            return (1);
    }
    else
        input_error();
    return (0);
}

void check_number_of_p_e(void)
{
    t_data *data;
    int i;
    int j;
    int count_e;
    int count_p;

    data = get_data();
    count_e = 0;
    count_p = 0;
    j = 0;
    while (j < data->w)
    {
        i = 0;
        while (i < data->h)
        {
            if (data->map[i][j] == 'P')
            {
                count_p++;
                if (count_p != 1)
                    map_error();
            }
            else if (data->map[i][j] == 'E')
            {
                count_e++;
                if (count_e != 1)
                    map_error();
            }
            i++;
        }
        j++;
    }
}

void check_valid_char()
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
            if (data->map[i][j] == 'E' || data->map[i][j] == 'P' || data->map[i][j] == 'C' || data->map[i][j] == '1' || data->map[i][j] == '0' || data->map[i][j] == '\n')
            {
                i++;
            }
            else
                map_error();
        }
        j++;
    }
}

// void check_down(int x, int y)
// {
//     t_data *data;

//     data = get_data();
//         printf("left");
//         if (data->tmp_map[x + 1][y] == '0')
//         {
//             check_left(x, y);
//             check_right(x, y);
//             check_up(x, y);
//             check_down(x + 1, y);
//         }
//         if (data->tmp_map[x + 1][y] == '1')
//         {
//             printf("wall\n");
//             return;

//         }
//         if (data->tmp_map[x + 1][y] == 'C')
//         {
//             printf("collectable\n");
//             data->check_collectable_count--;
//             check_left(x, y);
//             check_right(x, y);
//             check_up(x, y);
//             check_down(x + 1, y);
//         }
//         if (data->tmp_map[x + 1][y] == 'E')
//         {
//             data->exit_flag++;
//             check_left(x, y);
//             check_right(x, y);
//             check_up(x, y);
//             check_down(x + 1, y);
//             printf("exit");
//         }
//         if (data->check_collectable_count == 0 && data->exit_flag == 1)
//         {
//             data->flag = 1;
//         }
// }

// void check_up(int x, int y)
// {
//     t_data *data;

//     data = get_data();
//         printf("left");
//         if (data->tmp_map[x - 1][y] == '0')
//         {
//             check_left(x, y);
//             check_right(x, y);
//             check_up(x - 1, y);
//             check_down(x, y);
//         }
//         if (data->tmp_map[x - 1][y] == '1')
//         {
//             printf("wall\n");
//             return;
//         }
//         if (data->tmp_map[x - 1][y] == 'C')
//         {
//             printf("collectable\n");
//             data->check_collectable_count--;
//             check_left(x, y);
//             check_right(x, y);
//             check_up(x - 1, y);
//             check_down(x, y);
//         }
//         if (data->tmp_map[x - 1][y] == 'E')
//         {
//             data->exit_flag++;
//             check_left(x, y);
//             check_right(x, y);
//             check_up(x - 1, y);
//             check_down(x, y);
//             printf("exit");
//         }
//         if (data->check_collectable_count == 0 && data->exit_flag == 1)
//         {
//             data->flag = 1;
//         }
// }

// void check_right(int x, int y)
// {
//     t_data *data;

//     data = get_data();
//         printf("left");
//         if (data->tmp_map[x][y + 1] == '0')
//         {
//             check_left(x, y);
//             check_right(x, y + 1);
//             check_up(x, y);
//             check_down(x, y);
//         }
//         if (data->tmp_map[x][y + 1] == '1')
//         {
//             printf("wall\n");
//             return;
//         }
//         if (data->tmp_map[x][y + 1] == 'C')
//         {
//             printf("collectable\n");
//             data->check_collectable_count--;
//             check_left(x, y);
//             check_right(x, y + 1);
//             check_up(x, y);
//             check_down(x, y);
//         }
//         if (data->tmp_map[x][y + 1] == 'E')
//         {
//             data->exit_flag++;
//             check_left(x, y);
//             check_right(x, y + 1);
//             check_up(x, y);
//             check_down(x, y);
//             printf("exit");
//         }
//         if (data->check_collectable_count == 0 && data->exit_flag == 1)
//         {
//             data->flag = 1;
//         }
// }

// void check_left(int x, int y)
// {
//     t_data *data;

//     data = get_data();
//         printf("left");
//         if (data->tmp_map[x][y - 1] == '0')
//         {
//             data->tmp_map[x][y] = '1';
//             data->tmp_map[x][y - 1] = 'p';
//         }
//         if (data->tmp_map[x][y - 1] == '1')
//         {
//             printf("wall\n");
//             return;
//         }
//         if (data->tmp_map[x][y - 1] == 'C')
//         {
//             printf("collectable\n");
//             data->tmp_map[x][y] = '1';
//             data->tmp_map[x][y - 1] = 'p';
//             data->check_collectable_count--;
//         }
//         if (data->tmp_map[x][y - 1] == 'E')
//         {
//             data->exit_flag++;
//             data->tmp_map[x][y] = '1';
//             data->tmp_map[x][y - 1] = 'p';
//             printf("exit");
//         }
//         if (data->check_collectable_count == 0 && data->exit_flag == 1)
//         {
//             data->flag = 1;
//         }
// }

// void flood_fill(void)
// {
//     int x;
//     int y;

//     t_data *data;

//     data = get_data();
//     get_player_position();
//     x = data->pos_x;
//     y = data->pos_y;
//     while (data->tmp_map[x][y] == '0' || data->tmp_map[x][y] == 'C' || data->tmp_map[x][y] == 'E')
//     {
//         while (data->tmp_map[x][y] == '0' || data->tmp_map[x][y] == 'C' || data->tmp_map[x][y] == 'E')
//         {
//         printf("flood fill\n");
//         check_left(x, y);
//         // check_up(x, y);
//         // check_down(x, y);
//         // check_right(x, y);
//         y++;
//         }
//         x++;
//     }
//     x++;
//     if (data->flag != 1)
//         map_error_valid_path();
// }

// void flood_fill(void)
// {
//     int x;
//     int y;

//     t_data *data;

//     data = get_data();
//     get_player_position();
//     x = data->pos_x;
//     y = data->pos_y;
//     if ()
//     {
//         printf("flood fill\n");
//         check_left(x, y);
//         check_up(x, y);
//         check_down(x, y);
//         check_right(x, y);
//         y++;
//         x++;
//     }
//     if (data->flag != 1)
//         map_error_valid_path();
// }

void floodfill(char **map, char u, char v, int x, int y)
{
    t_data *data = get_data();
    if (map[x][y] == 'P' || map[x][y] == '0' || map[x][y] == 'C' || map[x][y] == 'E')
    {
        if (map[x][y] == 'C')
            data->check_collectable_count--;
        if (map[x][y] == 'E')
            data->exit_flag = 1;
        map[x][y] = 'D';
        printf("MAMAMAMA\n");
        floodfill(map, u, v, x + 1, y);
        floodfill(map, u, v, x - 1, y);
        floodfill(map, u, v, x, y - 1);
        floodfill(map, u, v, x, y + 1);
    }
}

void check_map(void)
{
    int x;
    int y;
    t_data *data;
    data = get_data();
    get_player_position();
    x = data->pos_x;
    y = data->pos_y;
    check_valid_char();
    check_number_of_p_e();
    check_top_bottom_walls();
    check_side_walls();
    floodfill(data->map, '0', 'D', x, y);
    printf("the flags coins : %d, exit ; %d", data->check_collectable_count, data->exit_flag);
    if (data->check_collectable_count != 0 || data->exit_flag != 1)
    {
        printf("WHY OH WHY\n");
        map_error_valid_path();
    }
}
