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
	int		collectable_count;
	void	*player;
	void	*exit;
	char 	**map;
	char 	**tmp_map;
	int		pos_x;
	int 	pos_y;
	int 	move_counter;
}			t_data;


void 	input_error(void);
void input_error_map_path(void);
void input_error_invalid_map(void);
void map_error(void);

t_data 	*get_data(void);
void    init_data(char *argv, int argc);
void get_map_size(t_data *data, char argv[1]);
void    get_map(t_data *data, char *argv);
void get_tmp_map(char *argv);
int parse_for_init(int argc, char *argv);
void check_number_of_p_e(void);
void render_images(char tile, int x, int y);
int render_frame(t_data *data);
void check_map(void);

void move_up(void);

void move_down(void);

void move_left(void);

void move_right(void);

void init_other_data(void);


int close_win(void);

void get_player_position(void);

void get_collectable_count();

int win_game(void);

 #endif