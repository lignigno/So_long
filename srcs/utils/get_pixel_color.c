/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 19:16:15 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/06 20:11:09 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "public.h"

t_uint	get_pixel_color(const t_imgdata *img, t_uint x, t_uint y)
{
	return (*(int *)(img->addr + (y * img->width + x * (img->bpp / 8))));
}
