/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpilotte <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 16:00:44 by jpilotte          #+#    #+#             */
/*   Updated: 2022/06/24 16:00:47 by jpilotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
 #define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../library/libft/libft.h"


typedef struct s_data {
	void	*mlx;
	void	*win;
	char	*addr;
	char	**map;
	char	*map_name;
	int		map_fd;
	int		height;
	int		width;
	int		line_length;
	int		endian;
	int		moves;
	int		x_p;
	int		y_p;
	int		n_col;
	int		n_p;
	int		n_ex;
	void	*wall;
	void	*empty;
	void	*exit;
	void	*collect;
	void	*player;
}			t_data;


 #endif