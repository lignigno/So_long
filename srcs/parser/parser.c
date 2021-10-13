/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 04:40:02 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/13 05:06:22 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parser.h"
// #include "parser.h"

void	init_enemy(t_all *all)
{
	ssize_t	i;
	ssize_t	y;
	size_t	tmp;

	srand(time(NULL));
	// count_roads
	all->enemy.start_y = all->map.y;
	all->enemy.start_x = all->map.x;
	{
		y = 0;
		while (++y < all->map.height - 1)
			if (finde_road(&all->map, y))
				all->enemy.num_roads++;
	}
	all->enemy.roads = malloc(all->enemy.num_roads * sizeof(t_car));
	check_error(!all->enemy.roads);
	i = -1;
	while (++i < all->enemy.num_roads)
	{
		tmp = rand() % 3;
		all->enemy.roads[i].skin = all->enemy.cars[tmp];
		all->enemy.roads[i].height = (tmp < 2) + 1;
		all->enemy.roads[i].time_new_car = 0;
		all->enemy.roads[i].num_car = 0;
		y = 0;
		while (++y < all->map.height - 1)
			if (finde_road(&all->map, y))
				all->enemy.roads[i].y = y;
		all->enemy.roads[i].x = malloc((all->map.width / 2 + 1) * sizeof(ssize_t));
		check_error(!all->enemy.roads[i].x);
		y = -1;
		while (++y < all->map.width / 2 + 1)
			all->enemy.roads[i].x[y] = 0;
	}
}

// ____________________________________________________________________MAIN FUNC

void	parser(t_all *all, char const *argv[])
{
	load_map(all, argv[1]);
	check_map(all);
	pave_the_road(&all->map);
	set_objs_on_map(all);
	draw_map(all);
	set_xy_of_map(&all->map);
	init_enemy(all);
}
