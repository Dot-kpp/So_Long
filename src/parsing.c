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
        if (data->map[i][0] != '1' || data->map[i][data->w -1] != '1')
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
        if(ft_strncmp(&argv[count], ".ber", 4) != 0)
            input_error();
        else
            return (1);
    }
    else 
        input_error();  
    return(0);
}

//manage map valid to win

//manage number of 'P', 'E' to 1 only

void check_map(void)
{
    check_number_of_p_e();
    check_top_bottom_walls();
    check_side_walls();
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
        while(i < data->h)
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


//manage map surounded by walls only

//only works with rectangle map