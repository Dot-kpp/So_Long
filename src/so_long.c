#include "../include/so_long.h"

int main(int argc, char **argv)
{
    t_data *data;
    data = get_data();
    if (parse_for_init(argc, argv[1]) == 1)
    {   
        init_data(*argv, argc);
        get_map_size(data, argv[1]);
        data->win = mlx_new_window(data->mlx, data->width, data->height, "so_long");
        get_map(data, argv[1]); 
        render_frame();
        mlx_loop(data->mlx);
    }
}