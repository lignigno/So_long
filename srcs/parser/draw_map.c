/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 03:48:59 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/15 09:45:06 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	if_else(t_all *all, ssize_t *x, ssize_t *y)
{
	if (*x < 0 || *y < 0 || *x >= all->map.width || *y >= all->map.height)
		check_error(!img_on_img(&all->map.back, &all->objs[WATER],
				(*x + WINDOW_W / 2 - 1) * BLOCK_SIZE,
				(*y + WINDOW_H / 2 - 1) * BLOCK_SIZE));
	else
		check_error(!img_on_img(&all->map.back,
				&all->map.arr[*x][*y].texture,
				(*x + WINDOW_W / 2 - 1) * BLOCK_SIZE,
				(*y + WINDOW_H / 2 - 1) * BLOCK_SIZE));
}

// ____________________________________________________________________MAIN FUNC

void	draw_map(t_all *all)
{
	ssize_t	x;
	ssize_t	y;

	all->map.back.ptr = mlx_new_image(all->mlx,
			(all->map.width + WINDOW_W - 2) * BLOCK_SIZE,
			(all->map.height + WINDOW_H - 2) * BLOCK_SIZE);
	check_error(!all->map.back.ptr);
	all->map.back.height = (all->map.height + WINDOW_H - 2) * BLOCK_SIZE;
	all->map.back.addr = mlx_get_data_addr(all->map.back.ptr,
			&all->map.back.bpp, &all->map.back.width, &all->map.back.endian);
	y = -1 - (WINDOW_H / 2 - 1);
	while (++y < all->map.height + (WINDOW_H / 2 - 1))
	{
		x = -1 - (WINDOW_W / 2 - 1);
		while (++x < all->map.width + (WINDOW_W / 2 - 1))
			if_else(all, &x, &y);
	}
}
