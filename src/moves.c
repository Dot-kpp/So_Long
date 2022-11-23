/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:48:20 by jpilotte          #+#    #+#             */
/*   Updated: 2022/11/23 11:28:51 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_data	*data)
{
	int		x;
	int		y;

	data = get_data();
	x = data->pos_x;
	y = data->pos_y;
	if (data->map[x - 1][y] != '1')
	{
		if (data->map[x - 1][y] == 'E' )
		{
			if (data->collectable_count == 0)
				win_game();
			data->exit_walked = 1;
			data->map[x][y] = '0';
			data->map[x - 1][y] = 'P';
		}
		else
		{
			savior_up(x, y);
			data->move_counter++;
		}
		ft_printf("Number of move: %d\n", data->move_counter);
		ft_printf("Collectables remaining: %d\n\n", data->collectable_count);
	}
}

void	move_down(t_data	*data)
{
	int		x;
	int		y;

	data = get_data();
	x = data->pos_x;
	y = data->pos_y;
	if (data->map[x + 1][y] != '1')
	{
		if (data->map[x + 1][y] == 'E' )
		{
			if (data->collectable_count == 0)
				win_game();
			data->exit_walked = 1;
			data->map[x][y] = '0';
			data->map[x + 1][y] = 'P';
		}
		else
		{
			savior_down(x, y);
			data->move_counter++;
		}
		ft_printf("Number of move: %d\n", data->move_counter);
		ft_printf("Collectables remaining: %d\n\n", data->collectable_count);
	}
}

void	move_left(t_data	*data)
{
	int		x;
	int		y;

	data = get_data();
	x = data->pos_x;
	y = data->pos_y;
	if (data->map[x][y - 1] != '1')
	{
		if (data->map[x][y - 1] == 'E' )
		{
			if (data->collectable_count == 0)
				win_game();
			data->exit_walked = 1;
			data->map[x][y] = '0';
			data->map[x][y - 1] = 'P';
		}
		else
		{
			savior_left(x, y);
			data->move_counter++;
		}
		ft_printf("Number of move: %d\n", data->move_counter);
		ft_printf("Collectables remaining: %d\n\n", data->collectable_count);
	}
}

void	move_right(t_data	*data)
{
	int		x;
	int		y;

	data = get_data();
	x = data->pos_x;
	y = data->pos_y;
	if (data->map[x][y + 1] != '1')
	{
		if (data->map[x][y + 1] == 'E' )
		{
			if (data->collectable_count == 0)
				win_game();
			data->exit_walked = 1;
			data->map[x][y] = '0';
			data->map[x][y + 1] = 'P';
		}
		else
		{
			savior_right(x, y);
			data->move_counter++;
		}
		ft_printf("Number of move: %d\n", data->move_counter);
		ft_printf("Collectables remaining: %d\n\n", data->collectable_count);
	}
}
