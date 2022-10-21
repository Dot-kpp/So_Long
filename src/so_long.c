#include "../include/so_long.h"

void input_error(void)
{
    write(1, "Please enter a valid input: ./so_long map.ber\n", 47);
    exit (1);
}

void parse_for_init(int argc, char *argv)
{
    if (argc != 2)
        input_error();
    if (argv == NULL)
        input_error();
}

// int init_map_assets(t_data data)
// {
//     char *path;

//     path = "./Assets/wall.xpm";
//     data.wall = mlx_xpm_file_to_image (data.mlx, path, &data.width, &data.height);

//     return(1);
// }

// int render_map(t_data data, int x, int y)
// {
//     return (1);
// }

int main(int argc, char **argv)
{
    (void) argc;
    (void) argv;
    t_data data;

    char *path;

    path = "./Assets/wall.xpm";
    //parse_for_init(argc, *argv);
    
    data.mlx = mlx_init();
    data.wall = mlx_xpm_file_to_image (data.mlx, path, &data.width, &data.height);
    data.win = mlx_new_window(data.mlx, 500, 500, "so_long");
    mlx_put_image_to_window(data.mlx, data.win, data.wall, 0, 0);
    mlx_loop(data.mlx);
}