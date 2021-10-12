/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_on_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:23:06 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/11 18:40:48 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/public.h"
// #include "public.h"

t_imgdata	*img_on_img(t_imgdata *base, t_imgdata *top, ssize_t sx, ssize_t sy)
{
	ssize_t	x;
	ssize_t	y;
	t_uint	color;

	y = -1;
	while (++y < top->height)
	{
		x = -1;
		while (++x < top->width / (top->bpp / 8))
		{
			color = get_pixel_color(top, x, y);
			set_pixel_color(base, sx + x, sy + y, color);
		}
	}
	return (base);
}
