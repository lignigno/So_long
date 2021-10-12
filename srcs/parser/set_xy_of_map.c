/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_xy_of_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 03:49:50 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/12 06:14:53 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// ____________________________________________________________________MAIN FUNC

void	set_xy_of_map(t_map *map)
{
	ssize_t	x;
	ssize_t	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->arr[x][y].obj_id == PERS)
			{
				map->next_x -= (x - 1) * BLOCK_SIZE + ((WINDOW_W + 1) % 2 * BLOCK_SIZE / 2);
				map->next_y -= (y - 1) * BLOCK_SIZE + ((WINDOW_H + 1) % 2 * BLOCK_SIZE / 2);
				map->x = map->next_x;
				map->y = map->next_y;
				return ;
			}
		}
	}
}
