#include "../include/so_long.h"


int parse_for_init(int argc, char *argv)
{
    int count;

    if (argc == 2 && argv != NULL)
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


// you are here..
void get_map_size(t_data *data, char argv[1])
{
    (void) argv;
    data->height = 500;
    data->width = 500;
}

int main(int argc, char **argv)
{
    t_data *data;
    data = get_data();
    if (parse_for_init(argc, argv[1]) == 1)
    {   
        init_data(*argv, argc);
        get_map_size(data, argv[1]);
        data->win = mlx_new_window(data->mlx, data->width, data->height, "so_long");
        mlx_put_image_to_window(data->mlx, data->win, data->wall, 0, 0);
        mlx_put_image_to_window(data->mlx, data->win, data->floor, 32, 32);
        mlx_put_image_to_window(data->mlx, data->win, data->collectable, 32, 32);
        mlx_loop(data->mlx);
    }
}