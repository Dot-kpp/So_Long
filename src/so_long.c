#include "../include/so_long.h"

void esc_key(int keycode)
{
	if (keycode == 53)
	{
		printf("escaped window.");
		exit(0);
	}	
}

void	game_controls(int keycode, t_data *data)
{
	if (keycode == 2)
	{
		move_right(data);
		render_frame(data);
	}
	if (keycode == 0)
	{
		move_left(data);
		render_frame(data);
	}
	else if (keycode == 1)
	{
		move_down(data);
		render_frame(data);
	}
	else if (keycode == 13)
	{
		move_up(data);
		render_frame(data);
	}
}

int close_win(void)
{
	printf("Window closed!\n");
	exit(0);
}

int key_press_event(int keycode, t_data *data)
{
	esc_key(keycode);
	game_controls(keycode, data);
	return (0);
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
        get_map(data, argv[1]); 
		render_frame(data);
        mlx_hook(data->win, 2, 0, key_press_event, &data);
        mlx_hook(data->win, 17, 0, close_win, &data);
        mlx_loop(data->mlx);
    }
}