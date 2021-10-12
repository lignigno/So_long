/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:36:30 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/12 08:34:58 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/public.h"
// #include "public.h"

static void	set_from_to(t_all *all, ssize_t x[3], ssize_t y[3])
{
	x[0] = -all->map.x / BLOCK_SIZE - WINDOW_W / 2;
	x[1] = -all->map.x / BLOCK_SIZE + WINDOW_W / 2 + \
		!!(all->map.x % BLOCK_SIZE);
	y[0] = -all->map.y / BLOCK_SIZE - WINDOW_H / 2;
	y[1] = -all->map.y / BLOCK_SIZE + WINDOW_H / 2 + \
		!!(all->map.y % BLOCK_SIZE);
	x[0] *= (x[0] > 0);
	y[0] *= (y[0] > 0);
	if (x[1] > all->map.width - 2)
		x[1] = all->map.width - 2;
	if (y[1] > all->map.height - 2)
		y[1] = all->map.height - 2;
}

void	show_collectible(t_all *all, ssize_t x[3], ssize_t y[3])
{

	y[2] = y[0];
	while (++y[2] < y[1] + 2)
	{
		x[2] = x[0];
		while (++x[2] < x[1] + 2)
		{
			if (all->map.arr[x[2]][y[2]].obj_id == COLLECTIBLE)
				mlx_put_image_to_window(all->mlx, all->win,
					all->objs[COLLECTIBLE].ptr,
					all->map.x + (WINDOW_W / 2 + x[2] - 1) * BLOCK_SIZE,
					all->map.y + (WINDOW_H / 2 + y[2] - 1) * BLOCK_SIZE);
		}
	}
}

void	show_opened_exit(t_all *all, ssize_t x[3], ssize_t y[3])
{

	y[2] = y[0];
	while (++y[2] < y[1] + 2)
	{
		x[2] = x[0];
		while (++x[2] < x[1] + 2)
		{
			if (all->map.arr[x[2]][y[2]].obj_id == CLOSED_EXIT)
				mlx_put_image_to_window(all->mlx, all->win,
					all->objs[OPENED_EXIT].ptr,
					all->map.x + (WINDOW_W / 2 + x[2] - 1) * BLOCK_SIZE,
					all->map.y + (WINDOW_H / 2 + y[2] - 1) * BLOCK_SIZE);
		}
	}
}

void	show_finish(t_all *all)
{
	printf("3\n");
	sleep(1);
	printf("2\n");
	sleep(1);
	printf("1\n");
	sleep(1);
	end_game(all);
}

// ____________________________________________________________________MAIN FUNC

void	rendering(t_all *all)
{
	ssize_t	x[3];
	ssize_t	y[3];

	mlx_clear_window(all->mlx, all->win);
	if (all->num_items == FINISH)
		show_finish(all);
	set_from_to(all, x, y);
	mlx_put_image_to_window(all->mlx, all->win, all->map.back.ptr,
		all->map.x, all->map.y);
	show_collectible(all, x, y);
	if (all->num_items < 1)
		show_opened_exit(all, x, y);
	mlx_put_image_to_window(all->mlx, all->win,
		all->pers->current_move[all->pers->motion_frame].ptr,
		(WINDOW_W - 1) * BLOCK_SIZE / 2, (WINDOW_H - 1) * BLOCK_SIZE / 2);
}
