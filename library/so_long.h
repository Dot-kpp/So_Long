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
#include "./gnl/get_next_line.h"


int read_map(void);

typedef struct	s_data {
	void	*img;
} t_data;

typedef struct s_walls
{
	void	*img;
}	t_walls;

typedef struct s_floor
{
	void	*img;
}	t_floor;

typedef struct s_obstacle
{
	void	*img;
}	t_obstacle;

typedef struct s_collectables
{
	void	*img;
}	t_collectables;

typedef struct s_vars
{
	void	*mlx;
	void	*mlx_win;
	t_data data;
}	t_vars;

 #endif