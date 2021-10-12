/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 03:26:05 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/12 10:08:34 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/inits.h"

static void	load_taxi(t_all *all, t_imgdata *from_img, t_cut_param *param)
{
	param->start_x = TAXI_X * TILE_SIZE;
	param->start_y = TAXI_Y * TILE_SIZE;
	param->cut_by_y = TILE_SIZE * 2;
	param->new_height = BLOCK_SIZE * 2;
	cut_piece(all->mlx, from_img, &all->enemy.cars[TAXI], param);
}

static void	load_car(t_all *all, t_imgdata *from_img, t_cut_param *param)
{
	param->start_x = CAR_X * TILE_SIZE;
	param->start_y = CAR_Y * TILE_SIZE;
	param->cut_by_y = TILE_SIZE * 2;
	param->new_height = BLOCK_SIZE * 2;
	cut_piece(all->mlx, from_img, &all->enemy.cars[CAR], param);
}

static void	load_scar(t_all *all, t_imgdata *from_img, t_cut_param *param)
{
	param->start_x = SCAR_X * TILE_SIZE;
	param->start_y = SCAR_Y * TILE_SIZE;
	param->cut_by_y = TILE_SIZE;
	param->new_height = BLOCK_SIZE;
	cut_piece(all->mlx, from_img, &all->enemy.cars[SCAR], param);
}

void	init_enemy(t_all *all)
{
	t_imgdata	img;
	t_cut_param	param;

	img.ptr = mlx_xpm_file_to_image(all->mlx, "srcs/imgs/tilemap_packed.xpm",
			&img.width, &img.height);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.width, &img.endian);
	param.cut_by_x = TILE_SIZE * 2;
	param.new_width = BLOCK_SIZE * 2;
	load_taxi(all, &img, &param);
	load_car(all, &img, &param);
	load_scar(all, &img, &param);
	mlx_destroy_image(all->mlx, img.ptr);
}

// ____________________________________________________________________MAIN FUNC

t_all	*init(void)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	check_error(!all);
	all->mlx = mlx_init();
	all->map.next_x = 0;
	all->map.next_y = 0;
	all->my.map_x = ((WINDOW_W + 1) % 2 * BLOCK_SIZE / 2);
	all->my.map_y = ((WINDOW_H + 1) % 2 * BLOCK_SIZE / 2);
	all->my.wait_car = BLOCK_SIZE * 2 / (BLOCK_SIZE / STEP_PROPOTION * SPEED_C);
	all->my.wait_car += !!(BLOCK_SIZE * 2 \
		% (BLOCK_SIZE / STEP_PROPOTION * SPEED_C));
	all->my.wait_car *= (SEC / FPS);
	init_pers(all);
	init_objects(all);
	init_enemy(all);
	return (all);
}
