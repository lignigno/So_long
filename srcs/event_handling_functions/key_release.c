/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:44:16 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/09 19:52:51 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/public.h"
// #include "public.h"

// ____________________________________________________________________MAIN FUNC

int	key_release(int key, t_all *all)
{
	if (key == UP || key == DOWN)
		all->map.move_y = 0;
	else if (key == LEFT || key == RIGHT)
		all->map.move_x = 0;

	return (EXIT_SUCCESS);
}
