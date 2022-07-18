#include "./library/so_long.h"


/*
0 for an empty space,
1 for a wall,
C for a collectible,
E for a map exit,
P for the player’s starting position.
*/



void map_validate(void);

void player_validate(void);

void enemie_validate(void);

void wall_print(void){
	void	*mlx;
	void	*img;
	char	*relative_path = "./Assets/test.xpm";
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
}

void floor_print(void){
	void	*mlx;
	void	*img;
	char	*relative_path = "./Assets/test.xpm";
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
}

void obstical_print(void){
	void	*mlx;
	void	*img;
	char	*relative_path = "./Assets/test.xpm";
	int		img_width;
	int		img_height;

	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
}


void map_init(void);

void player_init(void);

void enemie_init(void);

void errors(void);

void window(void)
{
    void	*mlx;
	void	*mlx_win;
	t_data	img;
	int x;
	int y;

	x = 500;
	y = 500;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, x, y, "So_long my homie");
	img.img = mlx_new_image(mlx, x, y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

int main(void)
{
    window();
}