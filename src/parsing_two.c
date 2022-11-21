/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:04:25 by jpilotte          #+#    #+#             */
/*   Updated: 2022/11/21 12:06:51 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	floodfill(char u, char v, int x, int y)
{
	t_data	*data;

	data = get_data();
	if (data->map[x][y] == 'P' || data->map[x][y] == '0'
			|| data->map[x][y] == 'C' || data->map[x][y] == 'E')
	{
		if (data->map[x][y] == 'C')
			data->check_collectable_count--;
		if (data->map[x][y] == 'E')
			data->exit_flag = 1;
		data->map[x][y] = 'D';
		floodfill(u, v, x + 1, y);
		floodfill(u, v, x - 1, y);
		floodfill(u, v, x, y - 1);
		floodfill(u, v, x, y + 1);
	}
}
