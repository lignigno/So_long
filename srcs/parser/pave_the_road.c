/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pave_the_road.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 03:46:42 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/12 03:46:58 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// ____________________________________________________________________MAIN FUNC

void	pave_the_road(t_map *map)
{
	unsigned int	x;
	unsigned int	y;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->arr[x][y].obj_id == ROAD)
			{
				x = 0;
				while (++x < map->width - 1)
				{
					if (map->arr[x][y].obj_id != COLLECTIBLE &&
						map->arr[x][y].obj_id != CLOSED_EXIT)
						map->arr[x][y].obj_id = ROAD;
				}
				break ;
			}
		}
	}
}
