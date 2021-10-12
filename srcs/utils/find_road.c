/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_road.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:43:15 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/09 16:00:52 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "public.h"

int	finde_road(t_map *map, size_t y)
{
	ssize_t	x;

	x = 1;
	while (x < map->width - 1)
	{
		if (map->arr[x][y].obj_id == ROAD)
			return (1);
		x++;
	}
	return (0);
}
