/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 03:47:10 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/12 08:09:21 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/inits.h"
// #include "inits.h"

// __________________________________________________________________SUBFUNCTION

static void	load_sprite(void *mlx_ptr,
					t_imgdata *from_img,
					t_imgdata move_arr[],
					t_uint move_offset)
{
	size_t		i;
	t_cut_param	param;

	i = 0;
	while (i < 3)
	{
		param.start_x = (PERS_SPRITE_X + move_offset) * TILE_SIZE;
		param.start_y = (PERS_SET * PERS_SPRITE_Y + i) * TILE_SIZE;
		param.cut_by_x = TILE_SIZE;
		param.cut_by_y = TILE_SIZE;
		param.new_width = BLOCK_SIZE;
		param.new_height = BLOCK_SIZE;
		cut_piece(mlx_ptr, from_img, &move_arr[i], &param);
		i++;
	}
	move_arr[3] = move_arr[2];
	move_arr[2] = move_arr[0];
}

// ____________________________________________________________________MAIN FUNC

void	init_pers(t_all *all)
{
	t_imgdata	img;

	img.ptr = mlx_xpm_file_to_image(all->mlx, "srcs/imgs/tilemap_packed.xpm",
			&img.width, &img.height);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.width, &img.endian);
	all->pers = malloc(sizeof(t_pers));
	check_error(!all->pers);
	load_sprite(all->mlx, &img, all->pers->left, 0);
	load_sprite(all->mlx, &img, all->pers->down, 1);
	load_sprite(all->mlx, &img, all->pers->up, 2);
	load_sprite(all->mlx, &img, all->pers->right, 3);
	all->pers->current_move = &all->pers->down[0];
	all->pers->motion_frame = 0;
	all->num_items = 0;
	mlx_destroy_image(all->mlx, img.ptr);
}
