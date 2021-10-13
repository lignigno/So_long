/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:56:40 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/13 05:19:34 by lignigno         ###   ########.fr       */
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
	// collision_enemy(all, nearest_x, nearest_y);
}

void	generate_new_car(t_all *all, t_car *road)
{
	(void)all;
	road->x[road->num_car] = 0;
	road->num_car++;
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

	// move_enemy
	{
		ssize_t	i;
		ssize_t	j;

		all->enemy.start_y = all->map.y;
		all->enemy.start_x = all->map.x + (WINDOW_W / 2 - 2) * BLOCK_SIZE;
		i = -1;
		// перебрать каждую дорогу
		while (++i < all->enemy.num_roads)
		{
			j = -1;
			// изменить положение каждой машинки на этой дороге
			while (++j < all->enemy.roads[i].num_car)
				all->enemy.roads[i].x[j] += BLOCK_SIZE / STEP_PROPOTION * SPEED_C ;

			// здесь нужно поправить
			// если она доехала до конца то убрать её
			if (all->enemy.roads[i].x[all->enemy.roads[i].num_car - 1] > all->map.width * BLOCK_SIZE + all->map.x)
				all->enemy.roads[i].num_car--;

			// если можно сгенерировать, то генерировать
			if (get_time() > all->enemy.roads[i].time_new_car
				&& all->enemy.roads[i].num_car < all->map.width / 2 + 1)
			{
				generate_new_car(all, &all->enemy.roads[i]);
				all->enemy.roads[i].time_new_car = get_time() + \
					all->my.wait_car * (rand() % (all->map.width / 2 + 1) + 1);
			}
		}
	}

	printf("y %zi\n", all->enemy.roads[0].y);
	printf("num_car %zi\n", all->enemy.roads[0].num_car);
	printf("time_new_car %zu %zu\n", all->enemy.roads[0].time_new_car, get_time());
	for (ssize_t i = 0; i < all->enemy.roads[0].num_car; i++)
		printf("roads[0].x[%zi] %zi\n", i, all->enemy.roads[0].x[i]);
	printf("\n");

	rendering(all);

	return (EXIT_SUCCESS);
}
