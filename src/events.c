/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <jpilotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:03:57 by jpilotte          #+#    #+#             */
/*   Updated: 2022/11/18 16:32:36 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	esc_key(int keycode)
{
	if (keycode == 53)
	{
		ft_printf("_______________\n");
		ft_printf("escaped window.\n");
		ft_printf("_______________\n");
		exit(0);
	}	
}

void	game_controls(int keycode, t_data *data)
{
	if (keycode == 2)
	{
		get_player_position();
		move_right(data);
		render_frame(data);
	}
	if (keycode == 0)
	{
		get_player_position();
		move_left(data);
		render_frame(data);
	}
	else if (keycode == 1)
	{
		get_player_position();
		move_down(data);
		render_frame(data);
	}
	else if (keycode == 13)
	{
		get_player_position();
		move_up(data);
		render_frame(data);
	}
}

int	close_win(void)
{
	ft_printf("______________\n");
	ft_printf("Window closed!\n");
	ft_printf("______________\n");
	exit(0);
}

int	win_game(void)
{
	ft_printf("___________________________________________________\n");
	ft_printf("You Actually won?! Thats insane in the membrane!!!!\n");
	ft_printf("___________________________________________________\n");
	exit(0);
}

int	key_press_event(int keycode, t_data *data)
{
	esc_key(keycode);
	game_controls(keycode, data);
	return (0);
}
