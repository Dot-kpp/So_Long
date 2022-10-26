#include "../include/so_long.h"


void render_images(char tile, int x, int y)
{
    t_data *data;
    data = get_data();

    if (tile == '1')
    {
        mlx_put_image_to_window(data->mlx, data->win, data->wall, x, y);
    }
    if (tile == '0')
    {
        mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
    }
    if (tile == 'C')
    {
        mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
        mlx_put_image_to_window(data->mlx, data->win, data->collectable, x, y);
    }
    if (tile == 'P')
    {
        mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
        mlx_put_image_to_window(data->mlx, data->win, data->player, x, y);
    }
    if (tile == 'E')
    {
        mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
        mlx_put_image_to_window(data->mlx, data->win, data->exit, x, y);
    }
}

void render_frame(void)
{
    int x;
    int y;
    t_data *data;

    data = get_data();
    y = 0;
    while (y < data->w)
    {
        x = 0;
        while (x < data->h)
        {
            render_images(data->map[x][y], y * 32, x * 32);
            x++;
        }
        y++;
    }
}