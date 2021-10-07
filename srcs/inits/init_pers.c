/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 03:47:10 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/07 03:49:52 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inits.h"

// __________________________________________________________________SUBFUNCTION

static void	load_sprite(void *mlx_ptr,
					t_imgdata *from_img,
					t_imgdata move_arr[],
					t_uint move_offset)
{
	t_cut_param	param;

	for (size_t i = 0; i < 3; i++)
	{
		param.start_x = (PERS_SPRITE_X + move_offset) * (TILE_SIZE + 1);
		param.start_y = (PERS_SET * PERS_SPRITE_Y + i) * (TILE_SIZE + 1);
		param.cut_by_x = TILE_SIZE;
		param.cut_by_y = TILE_SIZE;
		param.new_width = BLOCK_SIZE;
		param.new_height = BLOCK_SIZE;
		move_arr[i] = cut_piece(mlx_ptr, from_img, &param);
	}
	move_arr[3] = move_arr[2];
	move_arr[2] = move_arr[0];
}

// ____________________________________________________________________MAIN FUNC

void	init_pers(t_all *all)
{
	t_imgdata	img;

	img.ptr = mlx_xpm_file_to_image(all->mlx, "srcs/imgs/tilemap.xpm", &img.width, &img.height);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.width, &img.endian);
	load_sprite(all->mlx, &img, all->pers.left, 0);
	load_sprite(all->mlx, &img, all->pers.down, 1);
	load_sprite(all->mlx, &img, all->pers.up, 2);
	load_sprite(all->mlx, &img, all->pers.right, 3);
	all->pers.current_move = &all->pers.down[0];
	all->pers.motion_frame = 0;
}
