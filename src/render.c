/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:48:41 by jpilotte          #+#    #+#             */
/*   Updated: 2022/11/21 12:11:17 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	render_e_savior(int x, int y)
{
	t_data	*data;

	data = get_data();
	mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
	mlx_put_image_to_window(data->mlx, data->win, data->exit, x, y);
}

void	render_p_savior(int x, int y)
{
	t_data	*data;

	data = get_data();
	mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
	mlx_put_image_to_window(data->mlx, data->win, data->player, x, y);
}

void	render_images(char tile, int x, int y)
{
	t_data	*data;

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
		render_p_savior(x, y);
	}
	if (tile == 'E')
	{
		render_e_savior(x, y);
	}
}

int	render_frame(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	data = get_data();
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
	return (0);
}
