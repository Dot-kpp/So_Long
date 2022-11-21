/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   savior.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:45:54 by jpilotte          #+#    #+#             */
/*   Updated: 2022/11/18 16:55:01 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	savior_up(int x, int y)
{
	t_data	*data;

	data = get_data();
	if (data->map[x - 1][y] == '0' || data->map[x - 1][y] == 'C')
	{
		if (data->map[x - 1][y] == 'C')
			data->collectable_count--;
		data->map[x][y] = '0';
		data->map[x - 1][y] = 'P';
	}
}

void	savior_down(int x, int y)
{
	t_data	*data;

	data = get_data();
	if (data->map[x + 1][y] == '0' || data->map[x + 1][y] == 'C')
	{
		if (data->map[x + 1][y] == 'C')
			data->collectable_count--;
		data->map[x][y] = '0';
		data->map[x + 1][y] = 'P';
	}
}

void	savior_left(int x, int y)
{
	t_data	*data;

	data = get_data();
	if (data->map[x][y - 1] == '0' || data->map[x][y - 1] == 'C')
	{
		if (data->map[x][y - 1] == 'C')
			data->collectable_count--;
		data->map[x][y] = '0';
		data->map[x][y - 1] = 'P';
	}
}

void	savior_right(int x, int y)
{
	t_data	*data;

	data = get_data();
	if (data->map[x][y + 1] == '0' || data->map[x][y + 1] == 'C')
	{
		if (data->map[x][y + 1] == 'C')
			data->collectable_count--;
		data->map[x][y] = '0';
		data->map[x][y + 1] = 'P';
	}
}
