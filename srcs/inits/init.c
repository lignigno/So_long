/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 03:26:05 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/07 03:49:06 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inits.h"

// ____________________________________________________________________MAIN FUNC

t_all	*init()
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	if (!all)
	{
		perror("all not alloc");
		exit(EXIT_FAILURE);
	}
	all->mlx = mlx_init();
	all->win = mlx_new_window(all->mlx, WINDOW_W * BLOCK_SIZE,
										WINDOW_H * BLOCK_SIZE,
										"UnicornGameS :)");
	init_pers(all);
	return (all);
}
