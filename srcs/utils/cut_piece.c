/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:01:11 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/15 08:39:35 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/public.h"

// _________________________________________________________________SUBFUNCTIONS

static void	redraw(	const t_imgdata *from_img,
				t_imgdata *resimg,
				const t_cut_param *param)
{
	size_t	i[2];
	t_uint	color;
	double	proportion_x;
	double	proportion_y;

	proportion_x = (double)param->cut_by_x / param->new_width;
	proportion_y = (double)param->cut_by_y / param->new_height;
	i[0] = -1;
	while (++i[0] < param->new_height)
	{
		i[1] = -1;
		while (++i[1] < param->new_width)
		{
			color = get_pixel_color(from_img,
					param->start_x + i[1] * proportion_x,
					param->start_y + i[0] * proportion_y);
			set_pixel_color(resimg, i[1], i[0], color);
		}
	}
}

// ____________________________________________________________________MAIN FUNC

void	cut_piece(	void *mlx_ptr,
						const t_imgdata *from_img,
						t_imgdata *to_img,
						const t_cut_param *param)
{
	to_img->height = param->new_height;
	to_img->ptr = mlx_new_image(mlx_ptr, param->new_width, param->new_height);
	to_img->addr = mlx_get_data_addr(to_img->ptr,
			&to_img->bpp, &to_img->width, &to_img->endian);
	redraw(from_img, to_img, param);
}
