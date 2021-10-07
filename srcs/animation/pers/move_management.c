/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:56:40 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/07 03:48:08 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/public.h"
// #include "public.h"

// ____________________________________________________________________MAIN FUNC

int	move_management(t_all *all)
{
	// просто проверять коллизию не запариваться на счёт перескока объектов
	// при столкновении не со стеной делать остальные изменения

	// move_mobs
	{}
	// move_pers
	{
		if (all->pers.move_y)
			all->pers.y += SPEED * all->pers.move_y;
		if (all->pers.move_x)
			all->pers.x += SPEED * all->pers.move_x;

		if (all->pers.move_y || all->pers.move_x || all->pers.motion_frame)
			all->pers.motion_frame += (all->pers.motion_frame == 3) * -4 + 1;

		if (all->pers.move_y < 0)
			all->pers.current_move = all->pers.up;
		else if (all->pers.move_y > 0)
			all->pers.current_move = all->pers.down;
		else if (all->pers.move_x < 0)
			all->pers.current_move = all->pers.left;
		else if (all->pers.move_x > 0)
			all->pers.current_move = all->pers.right;
	}	


	rendering(all);

	return (EXIT_SUCCESS);
}
