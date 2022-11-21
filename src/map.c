/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:48:07 by jpilotte          #+#    #+#             */
/*   Updated: 2022/11/21 12:02:45 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_map_size(t_data *data, char argv[1])
{
	int		i;
	int		fd;
	char	*rows;

	i = 0;
	fd = open(argv, O_RDONLY);
	rows = get_next_line(fd);
	data->h = 0;
	data->w = -1;
	while (rows[i])
	{
		i++;
		data->w++;
	}
	while (rows != NULL)
	{
		free(rows);
		rows = get_next_line(fd);
		data->h++;
	}
	data->height = data->h * 32;
	data->width = data->w * 32;
	free(rows);
	close(fd);
}

void	get_map(t_data *data, char *argv)
{
	int		i;
	int		fd;
	char	*temp;

	data = get_data();
	fd = open(argv, O_RDONLY);
	data->map = ft_calloc(data->h + 1, sizeof(char *));
	i = 0;
	while (i <= data->h)
	{
		temp = get_next_line(fd);
		data->map[i] = temp;
		i++;
	}
	data->map[i] = "\0";
	close(fd);
}

void	get_player_position(void)
{
	t_data	*data;
	int		i;
	int		j;

	data = get_data();
	j = 0;
	while (j <= data->w)
	{
		i = 0;
		while (i < data->h)
		{
			if (data->map[i][j] == 'P')
			{
				data->pos_x = i;
				data->pos_y = j;
			}
			i++;
		}
		j++;
	}
}

void	get_collectable_count(void)
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
			if (data->map[i][j] == 'C')
				data->collectable_count++;
			i++;
		}
		j++;
	}
	data->check_collectable_count = data->collectable_count;
}

void	check_map(void)
{
	int		x;
	int		y;
	t_data	*data;

	data = get_data();
	get_player_position();
	x = data->pos_x;
	y = data->pos_y;
	check_valid_char();
	check_number_of_p();
	check_number_of_e();
	check_top_bottom_walls();
	check_side_walls();
	floodfill('0', 'D', x, y);
	if (data->check_collectable_count != 0 || data->exit_flag != 1)
		map_error_valid_path();
}
