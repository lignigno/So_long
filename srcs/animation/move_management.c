/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:56:40 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/15 07:26:17 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"

// __________________________________________________________________SUBFUNCTION

void	generate_str_steps(t_all *all)
{
	ssize_t	i;
	size_t	tmpnum;
	char	tmpstr[20];

	i = -1;
	while (++i < 20)
		tmpstr[i] = '\0';
	tmpnum = all->num_steps;
	if (!tmpnum)
		tmpstr[0] = '0';
	i = !tmpnum;
	while (tmpnum)
	{
		tmpstr[i++] = tmpnum % 10 + '0';
		tmpnum /= 10;
	}
	tmpnum = i - 1;
	while (i-- > 0)
		all->str_steps[tmpnum - i + 8] = tmpstr[i];
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
	if (all->map.move_x || all->map.move_y)
		all->num_steps++;
	generate_str_steps(all);
	if (all->map.move_x || all->map.move_y)
		printf("%s\n", all->str_steps);
	rendering(all);
	return (EXIT_SUCCESS);
}
