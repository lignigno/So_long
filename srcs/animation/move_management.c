/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:56:40 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/12 08:27:55 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/public.h"
// #include "public.h"

void	set_variables(	t_all *all,
							int four_point[2][2],
							ssize_t nearest_x[2],
							ssize_t nearest_y[2])
{
	nearest_x[0] = (all->map.next_x - BLOCK_SIZE + all->my.map_x) / BLOCK_SIZE;
	nearest_y[0] = (all->map.next_y - BLOCK_SIZE + all->my.map_y) / BLOCK_SIZE;
	nearest_x[1] = nearest_x[0] - \
		!!((all->map.next_x + all->my.map_x) % BLOCK_SIZE);
	nearest_y[1] = nearest_y[0] - \
		!!((all->map.next_y + all->my.map_y) % BLOCK_SIZE);
	four_point[0][0] = \
		all->map.arr[-nearest_x[0]][-nearest_y[0]].obj_id == WALL;
	four_point[0][1] = \
		all->map.arr[-nearest_x[0]][-nearest_y[1]].obj_id == WALL;
	four_point[1][0] = \
		all->map.arr[-nearest_x[1]][-nearest_y[0]].obj_id == WALL;
	four_point[1][1] = \
		all->map.arr[-nearest_x[1]][-nearest_y[1]].obj_id == WALL;
}

void	collision_wall(	t_all *all,
							int four_point[2][2],
							ssize_t nearest_x[2],
							ssize_t nearest_y[2])
{
	if (all->map.move_x > 0 && (four_point[1][0] || four_point[1][1]))
		all->map.next_x = (nearest_x[0] + 1) * BLOCK_SIZE - all->my.map_x;
	else if (all->map.move_x < 0 && (four_point[0][0] || four_point[0][1]))
		all->map.next_x = (nearest_x[1] + 1) * BLOCK_SIZE - all->my.map_x;
	else if (all->map.move_y > 0 && (four_point[0][1] || four_point[1][1]))
		all->map.next_y = (nearest_y[0] + 1) * BLOCK_SIZE - all->my.map_y;
	else if (all->map.move_y < 0 && (four_point[0][0] || four_point[1][0]))
		all->map.next_y = (nearest_y[1] + 1) * BLOCK_SIZE - all->my.map_y;
}

void	collision_collectible(t_all *all,
								ssize_t x[2],
								ssize_t y[2])
{
	int	from_x;
	int	from_y;

	from_y = -1;
	while (++from_y < 2)
	{
		from_x = -1;
		while (++from_x < 2)
		{
			if (all->map.arr[-x[from_x]][-y[from_y]].obj_id == COLLECTIBLE
				&& (all->map.next_x - x[from_x]
				* BLOCK_SIZE + all->my.map_x) == BLOCK_SIZE
				&& (all->map.next_y - y[from_y]
				* BLOCK_SIZE + all->my.map_y) == BLOCK_SIZE)
			{
				all->num_items--;
				if (finde_road(&all->map, -y[from_y]))
					all->map.arr[-x[from_x]][-y[from_y]].obj_id = ROAD;
				else
					all->map.arr[-x[from_x]][-y[from_y]].obj_id = GROUND;
			}
		}
	}
}

void	collision_exit(t_all *all,
						ssize_t x[2],
						ssize_t y[2])
{
	int	from_x;
	int	from_y;

	from_y = -1;
	while (++from_y < 2)
	{
		from_x = -1;
		while (++from_x < 2)
		{
			if (all->map.arr[-x[from_x]][-y[from_y]].obj_id == CLOSED_EXIT
				&& (all->map.next_x - x[from_x]
				* BLOCK_SIZE + all->my.map_x) == BLOCK_SIZE
				&& (all->map.next_y - y[from_y]
				* BLOCK_SIZE + all->my.map_y) == BLOCK_SIZE)
			{
				if (all->num_items < 1)
					all->num_items = FINISH;
			}
		}
	}
}

void	check_collision(t_all *all)
{
	ssize_t	nearest_x[2];
	ssize_t	nearest_y[2];
	int		four_point[2][2];

	if (all->map.move_x)
		all->map.next_x -= (BLOCK_SIZE / STEP_PROPOTION) * \
			SPEED_P * all->map.move_x;
	if (all->map.move_y)
		all->map.next_y -= (BLOCK_SIZE / STEP_PROPOTION) * \
			SPEED_P * all->map.move_y;
	set_variables(all, four_point, nearest_x, nearest_y);
	collision_wall(all, four_point, nearest_x, nearest_y);
	collision_collectible(all, nearest_x, nearest_y);
	collision_exit(all, nearest_x, nearest_y);
}

// ____________________________________________________________________MAIN FUNC

int	move_management(t_all *all)
{
	if (get_time() < all->timer.frame_update)
		return (EXIT_SUCCESS);
	if (all->num_items == FINISH)
		rendering(all);
	all->timer.frame_update = get_time() + SEC / FPS;
	check_collision(all);

	// move_pers
	// тут нужен таймер;
	{
		all->map.x = all->map.next_x;
		all->map.y = all->map.next_y;
		if (all->map.move_y || all->map.move_x || all->pers->motion_frame)
			all->pers->motion_frame += (all->pers->motion_frame == 3) * -4 + 1;
		if (all->map.move_x < 0)
			all->pers->current_move = all->pers->left;
		else if (all->map.move_x > 0)
			all->pers->current_move = all->pers->right;
		else if (all->map.move_y < 0)
			all->pers->current_move = all->pers->up;
		else if (all->map.move_y > 0)
			all->pers->current_move = all->pers->down;
	}

	// move_mobs
	// тут нужен таймер;
	{}

	rendering(all);

	return (EXIT_SUCCESS);
}
