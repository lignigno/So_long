/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:04:28 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/06 20:05:58 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "public.h"

void	set_pixel_color(const t_imgdata *img, t_uint x, t_uint y, t_uint color)
{
	void	*addr_cell;

	addr_cell = img->addr + (y * img->width + x * (img->bpp / 8));
	*(int *)addr_cell = color;
}
