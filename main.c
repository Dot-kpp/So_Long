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

void wall_print(t_vars *vars){
	char	*relative_path = "./Assets/wall.xpm";
	int		img_width;
	int		img_height;

	vars->data.img = mlx_xpm_file_to_image(vars->mlx, relative_path, &img_width, &img_height);
}

void floor_print(t_vars *vars){
	char	*relative_path = "./Assets/floor.xpm";
	int		img_width;
	int		img_height;

	vars->data.img = mlx_xpm_file_to_image(vars->mlx, relative_path, &img_width, &img_height);
}

int window(void)
{
 
	t_vars vars;
	int x;
	int y;

	x = 500;
	y = 500;
	
	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx, x, y, "So_long my homie");
	wall_print(&vars);
	int i = 0;
	while (i < 10)
	{
		mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.data.img, i * 32, 0);
		i++;
	}

	mlx_loop(vars.mlx);
	return (0);
}

int main (void){
	window();
}