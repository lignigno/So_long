/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 03:45:07 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/12 08:11:43 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// ____________________________________________________________________MAIN FUNC

void	check_map(t_all *all)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	flags[2];

	flags[0] = 0;
	flags[1] = 0;
	y = 0;
	while (y < all->map.height)
	{
		x = 0;
		while (x < all->map.width)
		{
			check_error(all->map.arr[x][y].obj_id != WALL && (x == 0 || y == 0
					|| x == all->map.width - 1 || y == all->map.height - 1));
			all->num_items += all->map.arr[x][y].obj_id == COLLECTIBLE;
			flags[0] += all->map.arr[x][y].obj_id == CLOSED_EXIT;
			flags[1] += all->map.arr[x][y].obj_id == PERS;
			x++;
		}
		y++;
	}
	check_error(!all->num_items || !flags[0] || flags[1] != 1);
}
