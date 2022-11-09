#include "../include/so_long.h"

void move_up(void)
{
    t_data *data;
    data = get_data();
	int	x;
	int	y;

	x = data->pos_x;
	y = data->pos_y;
	if (data->map[x - 1][y] != '1')
	{
		if (data->map[x - 1][y] == 'E' )
		{
			if (data->collectable_count == 0)
				close_win();
		}
		else
		{
			if (data->map[x - 1][y] == '0' || data->map[x - 1][y] == 'C')
			{
				if (data->map[x - 1][y] == 'C')
					data->collectable_count--;
				data->map[x][y] = '0';
				data->map[x - 1][y] = 'P';
			}
			data->move_counter++;
		}
        printf("%d\n", data->collectable_count);
	}
}

void move_down(void)
{
    t_data *data;
    data = get_data();
	int	x;
	int	y;

	x = data->pos_x;
	y = data->pos_y;
	if (data->map[x + 1][y] != '1')
	{
		if (data->map[x + 1][y] == 'E' )
		{
			if (data->collectable_count == 0)
				close_win();
		}
		else
		{
			if (data->map[x + 1][y] == '0' || data->map[x + 1][y] == 'C')
			{
				if (data->map[x + 1][y] == 'C')
                {
					data->collectable_count--;
                }
				data->map[x][y] = '0';
				data->map[x + 1][y] = 'P';
			}
			data->move_counter++;
		}
	}
}

void move_left(void)
{
    t_data *data;
    data = get_data();
	int	x;
	int	y;

	x = data->pos_x;
	y = data->pos_y;
	if (data->map[x][y - 1] != '1')
	{
		if (data->map[x][y - 1] == 'E' )
		{
			if (data->collectable_count == 0)
				close_win();
		}
		else
		{
			if (data->map[x][y - 1] == '0' || data->map[x][y - 1] == 'C')
			{
				if (data->map[x][y - 1] == 'C')
					data->collectable_count--;
				data->map[x][y] = '0';
				data->map[x][y - 1] = 'P';
			}
			data->move_counter++;
		}
	}
}

void move_right(void)
{
    t_data *data;
    data = get_data();
	int	x;
	int	y;

	x = data->pos_x;
	y = data->pos_y;
	if (data->map[x][y + 1] != '1')
	{
		if (data->map[x][y + 1] == 'E' )
		{
			if (data->collectable_count == 0)
				close_win();
		}
		else
		{
			if (data->map[x][y + 1] == '0' || data->map[x][y + 1] == 'C')
			{
				if (data->map[x][y + 1] == 'C')
                {
					data->collectable_count--;
                }
				data->map[x][y] = '0';
				data->map[x][y + 1] = 'P';
			}
			data->move_counter++;
		}
	}
}

void move_exit(void)
{
    exit(0);
}

