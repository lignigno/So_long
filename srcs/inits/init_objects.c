/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 12:41:16 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/12 08:52:43 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/inits.h"
// #include "inits.h"

// __________________________________________________________________SUBFUNCTIONS
static void	set_start_xy_1(t_cut_param *param, int who)
{
	if (who == GROUND)
	{
		param->start_x = GROUND_X * TILE_SIZE;
		param->start_y = GROUND_Y * TILE_SIZE;
	}
	else if (who == UP_GROUND)
	{
		param->start_x = UP_GROUND_X * TILE_SIZE;
		param->start_y = UP_GROUND_Y * TILE_SIZE;
	}
	else if (who == DOWN_GROUND)
	{
		param->start_x = DOWN_GROUND_X * TILE_SIZE;
		param->start_y = DOWN_GROUND_Y * TILE_SIZE;
	}
	else if (who == WATER)
	{
		param->start_x = WATER_X * TILE_SIZE;
		param->start_y = WATER_Y * TILE_SIZE;
	}
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

static void	set_start_xy_2(t_cut_param *param, int who)
{
	if (who == WALL)
	{
		param->start_x = WALL_X * TILE_SIZE;
		param->start_y = WALL_Y * TILE_SIZE;
	}
	else if (who == ROAD)
	{
		param->start_x = ENEMY_X * TILE_SIZE;
		param->start_y = ENEMY_Y * TILE_SIZE;
	}
	else if (who == COLLECTIBLE)
	{
		param->start_x = COLLECTIBLE_X * TILE_SIZE;
		param->start_y = COLLECTIBLE_Y * TILE_SIZE;
	}
	else if (who == CLOSED_EXIT)
	{
		param->start_x = CLOSED_EXIT_X * TILE_SIZE;
		param->start_y = CLOSED_EXIT_Y * TILE_SIZE;
	}
	else if (who == OPENED_EXIT)
	{
		param->start_x = OPENED_EXIT_X * TILE_SIZE;
		param->start_y = OPENED_EXIT_Y * TILE_SIZE;
	}
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

static void	load_set_1(t_all *all, t_imgdata *from_img, t_cut_param *param)
{
	set_start_xy_1(param, GROUND);
	cut_piece(all->mlx, from_img, &all->objs[GROUND], param);
	set_start_xy_1(param, UP_GROUND);
	cut_piece(all->mlx, from_img, &all->objs[UP_GROUND], param);
	set_start_xy_1(param, DOWN_GROUND);
	cut_piece(all->mlx, from_img, &all->objs[DOWN_GROUND], param);
	set_start_xy_1(param, WATER);
	cut_piece(all->mlx, from_img, &all->objs[WATER], param);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

static void	load_set_2(t_all *all, t_imgdata *from_img, t_cut_param *param)
{
	set_start_xy_2(param, WALL);
	cut_piece(all->mlx, from_img, &all->objs[WALL], param);
	set_start_xy_2(param, ROAD);
	cut_piece(all->mlx, from_img, &all->objs[ROAD], param);
	set_start_xy_2(param, COLLECTIBLE);
	cut_piece(all->mlx, from_img, &all->objs[COLLECTIBLE], param);
	set_start_xy_2(param, CLOSED_EXIT);
	cut_piece(all->mlx, from_img, &all->objs[CLOSED_EXIT], param);
	set_start_xy_2(param, OPENED_EXIT);
	cut_piece(all->mlx, from_img, &all->objs[OPENED_EXIT], param);
}

// ____________________________________________________________________MAIN FUNC

void	init_objects(t_all *all)
{
	t_imgdata	img;
	t_cut_param	param;

	img.ptr = mlx_xpm_file_to_image(all->mlx, "srcs/imgs/tilemap_packed.xpm",
			&img.width, &img.height);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.width, &img.endian);
	param.cut_by_x = TILE_SIZE;
	param.cut_by_y = TILE_SIZE;
	param.new_width = BLOCK_SIZE;
	param.new_height = BLOCK_SIZE;
	load_set_1(all, &img, &param);
	load_set_2(all, &img, &param);
	mlx_destroy_image(all->mlx, img.ptr);
}
