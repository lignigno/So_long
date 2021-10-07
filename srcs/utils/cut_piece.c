/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:01:11 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/06 22:53:18 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "public.h"

// _________________________________________________________________SUBFUNCTIONS

static void	redraw(	const t_imgdata *from_img,
				t_imgdata *resimg,
				const t_cut_param *param)
{
	t_uint	color;
	double	proportion_x;
	double	proportion_y;

	proportion_x = (double)param->cut_by_x / param->new_width;
	proportion_y = (double)param->cut_by_y / param->new_height;
	for (size_t y = 0; y < param->new_height; y++)
	{
		for (size_t x = 0; x < param->new_width; x++)
		{
			color = get_pixel_color(from_img,
									param->start_x + x * proportion_x,
									param->start_y + y * proportion_y);
			set_pixel_color(resimg, x, y, color);
		}
	}
}

// ____________________________________________________________________MAIN FUNC

t_imgdata	cut_piece(	void *mlx_ptr,
						const t_imgdata *from_img,
						const t_cut_param *param)
{
	t_imgdata	resimg;

	resimg.height = param->new_height;
	resimg.ptr = mlx_new_image(mlx_ptr, param->new_width, param->new_height);
	resimg.addr = mlx_get_data_addr(resimg.ptr,
									&resimg.bpp,
									&resimg.width,
									&resimg.endian);
	redraw(from_img, &resimg, param);
	return (resimg);
}
