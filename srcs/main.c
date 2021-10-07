/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:22:24 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/07 03:00:23 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "public.h"

void	load_sprite(void *mlx_ptr,
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

// ____________________________________________________________________MAIN FUNC

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;

// init start		t_all	*init()

	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
	{
		perror("all not alloc");
		exit(EXIT_FAILURE);
	}
	// return all;
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, WINDOW_W * BLOCK_SIZE,
										WINDOW_H * BLOCK_SIZE,
										"UnicornGameS :)");
	init_pers(all);

// init end

	// mlx_put_image_to_window(all->mlx, all->win, all->pers.left[0].ptr, 0 * BLOCK_SIZE, 0 * BLOCK_SIZE);
	// mlx_put_image_to_window(all->mlx, all->win, all->pers.left[1].ptr, 0 * BLOCK_SIZE, 1 * BLOCK_SIZE);
	// mlx_put_image_to_window(all->mlx, all->win, all->pers.left[2].ptr, 0 * BLOCK_SIZE, 2 * BLOCK_SIZE);
	// mlx_put_image_to_window(all->mlx, all->win, all->pers.left[3].ptr, 0 * BLOCK_SIZE, 3 * BLOCK_SIZE);

	// mlx_put_image_to_window(all->mlx, all->win, all->pers.down[0].ptr, 1 * BLOCK_SIZE, 0 * BLOCK_SIZE);
	// mlx_put_image_to_window(all->mlx, all->win, all->pers.down[1].ptr, 1 * BLOCK_SIZE, 1 * BLOCK_SIZE);
	// mlx_put_image_to_window(all->mlx, all->win, all->pers.down[2].ptr, 1 * BLOCK_SIZE, 2 * BLOCK_SIZE);
	// mlx_put_image_to_window(all->mlx, all->win, all->pers.down[3].ptr, 1 * BLOCK_SIZE, 3 * BLOCK_SIZE);

	// mlx_put_image_to_window(all->mlx, all->win, all->pers.up[0].ptr, 2 * BLOCK_SIZE, 0 * BLOCK_SIZE);
	// mlx_put_image_to_window(all->mlx, all->win, all->pers.up[1].ptr, 2 * BLOCK_SIZE, 1 * BLOCK_SIZE);
	// mlx_put_image_to_window(all->mlx, all->win, all->pers.up[2].ptr, 2 * BLOCK_SIZE, 2 * BLOCK_SIZE);
	// mlx_put_image_to_window(all->mlx, all->win, all->pers.up[3].ptr, 2 * BLOCK_SIZE, 3 * BLOCK_SIZE);

	// mlx_put_image_to_window(all->mlx, all->win, all->pers.right[0].ptr, 3 * BLOCK_SIZE, 0 * BLOCK_SIZE);
	// mlx_put_image_to_window(all->mlx, all->win, all->pers.right[1].ptr, 3 * BLOCK_SIZE, 1 * BLOCK_SIZE);
	// mlx_put_image_to_window(all->mlx, all->win, all->pers.right[2].ptr, 3 * BLOCK_SIZE, 2 * BLOCK_SIZE);
	// mlx_put_image_to_window(all->mlx, all->win, all->pers.right[3].ptr, 3 * BLOCK_SIZE, 3 * BLOCK_SIZE);
	
	mlx_hook(all->win, 2, 0, key_press, all);
	mlx_hook(all->win, 3, 0, key_release, all);
	mlx_hook(all->win, 17, 0, end_game, all);
	mlx_loop_hook(all->mlx, move_management, all);
	mlx_loop(all->mlx);

	return 0;
}
