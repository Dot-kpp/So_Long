/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:48:29 by jpilotte          #+#    #+#             */
/*   Updated: 2022/11/21 12:06:09 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_top_bottom_walls(void)
{
	t_data	*data;
	int		j;

	data = get_data();
	j = 0;
	while (j <= data->w - 1)
	{
		if (data->map[0][j] != '1' || data->map[data->h - 1][j] != '1')
			map_error();
		j++;
	}
}

void	check_side_walls(void)
{
	t_data	*data;
	int		i;

	data = get_data();
	i = 0;
	while (i <= data->h - 1)
	{
		if (data->map[i][0] != '1' || data->map[i][data->w - 1] != '1')
			map_error();
		i++;
	}
}

void	check_number_of_p(void)
{
	t_data	*data;
	int		i;
	int		j;
	int		count_p;

	data = get_data();
	count_p = 0;
	j = 0;
	while (j < data->w)
	{
		i = 0;
		while (i < data->h)
		{
			if (data->map[i][j] == 'P')
			{
				count_p++;
				if (count_p != 1)
					map_error();
			}
			i++;
		}
		j++;
	}
}

void	check_number_of_e(void)
{
	t_data	*data;
	int		i;
	int		j;
	int		count_e;

	data = get_data();
	count_e = 0;
	j = 0;
	while (j < data->w)
	{
		i = 0;
		while (i < data->h)
		{
			if (data->map[i][j] == 'E')
			{
				count_e++;
				if (count_e != 1)
					map_error();
			}
			i++;
		}
		j++;
	}
}

void	check_valid_char(void)
{
	t_data	*data;
	int		i;
	int		j;

	data = get_data();
	j = 0;
	while (j < data->w)
	{
		i = 0;
		while (i < data->h)
		{
			if (data->map[i][j] == 'E' || data->map[i][j] == 'P'
					|| data->map[i][j] == 'C' || data->map[i][j] == '1'
					|| data->map[i][j] == '0' || data->map[i][j] == '\n')
			{
				i++;
			}
			else
				map_error();
		}
		j++;
	}
}
