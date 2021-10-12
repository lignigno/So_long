/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:17:05 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/12 09:39:37 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUBLIC_H
# define PUBLIC_H

# include <sys/time.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include "structs.h"

# define SEC 1000000
# define FPS 17

# define WINDOW_W 16
# define WINDOW_H 9
# define BLOCK_SIZE 64

// KEY CODES
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define TILE_SIZE 16
# define PERS_SPRITE_Y 3
# define PERS_SPRITE_X 23
# define WALL_Y 2
# define WALL_X 21
# define GROUND_Y 1
# define GROUND_X 1
# define UP_GROUND_Y 2
# define UP_GROUND_X 1
# define DOWN_GROUND_Y 0
# define DOWN_GROUND_X 1
# define WATER_X 9
# define WATER_Y 7
# define ENEMY_X 12
# define ENEMY_Y 2
# define COLLECTIBLE_X 9
# define COLLECTIBLE_Y 9
# define CLOSED_EXIT_X 12
# define CLOSED_EXIT_Y 10
# define OPENED_EXIT_X 12
# define OPENED_EXIT_Y 11
# define TAXI	0
# define TAXI_X	18
# define TAXI_Y	14
# define CAR	1
# define CAR_X	18
# define CAR_Y	16
# define SCAR	2
# define SCAR_X	21
# define SCAR_Y	17

# define PERS_SET 2

// if (BLOCK_SIZE / STEP_PROPOTION * SPEED > BLOCK_SIZE)
//     undefined behavior;
# define STEP_PROPOTION 16
# define SPEED_P 4
# define SPEED_C 6

// BLOCK_SIZE * 2 / (BLOCK_SIZE / STEP_PROPOTION * SPEED_C)
// VAR = BLOCK_SIZE * 2 / (BLOCK_SIZE / STEP_PROPOTION * SPEED_C) +
// !!(BLOCK_SIZE * 2 % (BLOCK_SIZE / STEP_PROPOTION * SPEED_C))
// VAR * (SEC / FPS) time_wait_for_car

# define TXTC_BLUE "\e[1;38;2;0;183;224m"
# define TXTC_RED "\e[1;38;2;181;0;0m"
# define UNSET "\e[m"

size_t		get_time(void);
t_all		*init(void);
size_t		ft_strlen(const char *str);
void		parser(t_all *all, char const *argv[]);
int			key_press(int key, t_all *all);
int			key_release(int key, t_all *all);
int			end_game(t_all *all);
int			move_management(t_all *all);
void		rendering(t_all *all);
void		check_error(unsigned int error_condition);
int			gnl(int fd, char **line);
int			finde_road(t_map *map, size_t y);
t_imgdata	*img_on_img(t_imgdata *base, t_imgdata *top, ssize_t sx, ssize_t sy);
void		set_pixel_color(const t_imgdata *img, t_uint x, t_uint y,
				t_uint color);
t_uint		get_pixel_color(const t_imgdata *img, t_uint x, t_uint y);
void		cut_piece(void *mlx_ptr, const t_imgdata *from_img,
				t_imgdata *to_img, const t_cut_param *param);

#endif