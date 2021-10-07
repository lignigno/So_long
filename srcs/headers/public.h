/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   public.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:17:05 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/07 03:45:15 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUBLIC_H
#define PUBLIC_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "mlx.h"
#include "structs.h"

#define WINDOW_W 16
#define WINDOW_H 9
#define BLOCK_SIZE 128

#define ESC 53
#define UP 126
#define DOWN 125
#define LEFT 123
#define RIGHT 124

#define TILE_SIZE 16
#define	PERS_SPRITE_Y 3
#define	PERS_SPRITE_X 23
// PERS_SET : {0, 1, 2, 3, 4, 5}
#define PERS_SET 5
#define SPEED (BLOCK_SIZE / 4)

#define TXTC_BLUE "\e[1;38;2;0;183;224m"
#define UNSET "\e[m"

t_all	*init();
int	key_press(int key, t_all *all);
int	key_release(int key, t_all *all);
int	end_game(t_all *all);
int	move_management(t_all *all);
void	rendering(t_all *all);

void	set_pixel_color(const t_imgdata *img, t_uint x, t_uint y, t_uint color);
t_uint	get_pixel_color(const t_imgdata *img, t_uint x, t_uint y);
t_imgdata	cut_piece (	void *mlx_ptr,
						const t_imgdata *from_img,
						const t_cut_param *param);

// 23 11
#endif