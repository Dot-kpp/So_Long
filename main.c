#include <mlx.h>
#include "so_long.h"


void map_validate(void){
	
}

void player_validate(void);

void enemie_validate(void);

void map_init(void);

void player_init(void);

void enemie_init(void);

void errors(void);

void window(void)
{
    void	*mlx;
	void	*mlx_win;
	t_data	img;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "So_long my homie");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

int main(void)
{
    window();
}