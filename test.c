/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 17:42:21 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/09 18:00:10 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "srcs/headers/public.h"

int main(int argc, char const *argv[])
{
	t_all	all;

	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, 1920, 1080,
										"UnicornGameS :)");

	t_imgdata base;

	base.ptr = mlx_new_image(all.mlx, 1600, 900);
	base.height = 900;
	base.addr = mlx_get_data_addr(base.ptr, &base.bpp, &base.width, &base.endian);

	for (size_t y = 0; y < base.height; y++)
		for (size_t x = 0; x < base.width / (base.bpp / 8); x++)
			set_pixel_color(&base, x, y, 0x404040);
	
	t_imgdata	img;
	
	img.ptr = mlx_xpm_file_to_image(all.mlx, "srcs/imgs/tilemap_packed.xpm",
			&img.width, &img.height);
	img.addr = mlx_get_data_addr(img.ptr, &img.bpp, &img.width, &img.endian);

	t_imgdata	top;
	t_cut_param	param;

	param.start_x = CLOSED_EXIT_X * TILE_SIZE;
	param.start_y = CLOSED_EXIT_Y * TILE_SIZE;
	param.cut_by_x = TILE_SIZE;
	param.cut_by_y = TILE_SIZE;
	param.new_width = BLOCK_SIZE;
	param.new_height = BLOCK_SIZE;
	cut_piece(all.mlx, &img, &top, &param);

	img_on_img(&base, &top, 100, 100);
	
	mlx_put_image_to_window(all.mlx, all.win, base.ptr, 0,0);
	// mlx_put_image_to_window(all.mlx, all.win, top.ptr, 100,100);
	mlx_loop(all.mlx);
	
	return 0;
}
