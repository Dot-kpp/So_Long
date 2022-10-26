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
#include "../libft/headers/libft.h"


typedef struct s_data {
	void	*mlx;
	void	*win;
	int		height;
	int		h;
	int		width;
	int		w;
	void	*wall;
	void	*floor;
	void	*collectable;
	void	*player;
	void	*exit;
	char 	**map;
}			t_data;


void 	input_error(void);
t_data 	*get_data(void);
void    init_data(char *argv, int argc);
void get_map_size(t_data *data, char argv[1]);
void    get_map(t_data *data, char *argv);
int parse_for_init(int argc, char *argv);
void render_images(char tile, int x, int y);
void render_frame(void);
void move_up(t_data *data);
void move_down(t_data *data);
void move_left(t_data *data);
void move_right(t_data *data);
void move_exit(t_data *data);

 #endif