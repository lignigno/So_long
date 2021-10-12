/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:32:09 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/09 19:52:24 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/public.h"
// #include "public.h"

// ____________________________________________________________________MAIN FUNC

int	key_press(int key, t_all *all)
{
	if (key == ESC)
		end_game(all);

	if (key == UP)
		all->map.move_y = -1;
	else if (key == DOWN)
		all->map.move_y = 1;
	else if (key == LEFT)
		all->map.move_x = -1;
	else if (key == RIGHT)
		all->map.move_x = 1;

	if (key == UP || key == DOWN)
		all->map.move_x = 0;
	else if (key == LEFT || key == RIGHT)
		all->map.move_y = 0;

	return (EXIT_SUCCESS);
}
