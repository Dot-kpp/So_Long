#include <mlx.h>
#include "so_long.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 920, 1080, "So_long my homie");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	my_mlx_pixel_put(&img, 35, 35, 0x00FF0000);
	my_mlx_pixel_put(&img, 25, 25, 0x00FF0000);
	my_mlx_pixel_put(&img, 15, 15, 0x00FF0000);
	my_mlx_pixel_put(&img, 10, 10, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 7, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 6, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 4, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 3, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 2, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 1, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
