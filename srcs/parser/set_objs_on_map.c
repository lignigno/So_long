/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_objs_on_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 03:47:46 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/12 07:54:15 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// ____________________________________________________________________MAIN FUNC

void	set_objs_on_map(t_all *all)
{
	unsigned int	x;
	unsigned int	y;

	y = -1;
	while (++y < all->map.height)
	{
		x = -1;
		while (++x < all->map.width)
		{
			if ((all->map.arr[x][y].obj_id == COLLECTIBLE
				|| all->map.arr[x][y].obj_id == PERS)
				&& finde_road(&all->map, y))
				all->map.arr[x][y].texture = all->objs[ROAD];
			else if (all->map.arr[x][y].obj_id == COLLECTIBLE
				|| all->map.arr[x][y].obj_id == PERS)
				all->map.arr[x][y].texture = all->objs[GROUND];
			else
				all->map.arr[x][y].texture = \
					all->objs[all->map.arr[x][y].obj_id];
		}
	}
}
