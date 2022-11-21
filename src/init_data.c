/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:47:57 by jpilotte          #+#    #+#             */
/*   Updated: 2022/11/18 16:28:32 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

t_data	*get_data(void)
{
	static t_data	*data = NULL;

	if (data == NULL)
		data = ft_calloc(1, sizeof(t_data));
	return (data);
}

void	init_data(char *argv, int argc)
{
	t_data	*data;

	(void) argc;
	(void) argv;
	data = get_data();
	data->flag = -1;
	data->move_counter = 0;
}

void	init_other_data(void)
{
	int		h;
	int		w;
	char	*path;
	t_data	*data;

	data = get_data();
	data->mlx = mlx_init();
	path = "./Assets/wall.xpm";
	data->wall = mlx_xpm_file_to_image (data->mlx, path, &w, &h);
	path = "./Assets/floor.xpm";
	data->floor = mlx_xpm_file_to_image (data->mlx, path, &w, &h);
	path = "./Assets/coin.xpm";
	data->collectable = mlx_xpm_file_to_image (data->mlx, path, &w, &h);
	path = "./Assets/player.xpm";
	data->player = mlx_xpm_file_to_image (data->mlx, path, &w, &h);
	path = "./Assets/exit.xpm";
	data->exit = mlx_xpm_file_to_image (data->mlx, path, &w, &h);
}

int	parse_for_init(int argc, char *argv)
{
	int	count;

	if (open(argv, O_RDONLY) == -1)
		input_error_map_path();
	else if (argc == 2 && argv != NULL)
	{
		count = ft_strlen(argv) - 4;
		if (ft_strncmp(&argv[count], ".ber", 4) != 0)
			input_error();
		else
			return (1);
	}
	else
		input_error();
	return (0);
}
