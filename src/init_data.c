#include "../include/so_long.h"

t_data *get_data(void)
{
    static t_data *data = NULL;

    if(data == NULL)
        data = ft_calloc(1, sizeof(t_data));

    return (data);
}

void    init_data(char *argv, int argc)
{
    (void) argc;
    (void) argv;
    t_data  *data;
    char *path;

    data = get_data();

    data->mlx = mlx_init();

    path = "./Assets/wall.xpm";
    
    data->wall = mlx_xpm_file_to_image (data->mlx, path, &data->width, &data->height);
    
    path = "./Assets/floor.xpm";

    data->floor = mlx_xpm_file_to_image (data->mlx, path, &data->width, &data->height);
    
    path = "./Assets/coin.xpm";

    data->collectable = mlx_xpm_file_to_image (data->mlx, path, &data->width, &data->height);
}