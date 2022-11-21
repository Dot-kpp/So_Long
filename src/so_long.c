/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 14:48:50 by jpilotte          #+#    #+#             */
/*   Updated: 2022/11/18 15:15:46 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = get_data();
	if (parse_for_init(argc, argv[1]) == 1)
	{
		init_data(*argv, argc);
		get_map_size(data, argv[1]);
		get_map(data, argv[1]);
		get_collectable_count();
		check_map();
		free_dbl_arr(data->map);
		get_map(data, argv[1]);
		init_other_data();
		data->win = mlx_new_window(data->mlx,
				data->width, data->height, "so_long");
		render_frame(data);
		mlx_hook(data->win, 2, 0, key_press_event, &data);
		mlx_hook(data->win, 17, 0, close_win, &data);
		mlx_loop(data->mlx);
	}
}
