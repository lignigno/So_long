/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 03:26:05 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/15 07:19:54 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/inits.h"

// __________________________________________________________________SUBFUNCTION

void	init_str_steps(char str[], const char *init_str)
{
	size_t	i;

	i = -1;
	while (init_str[++i])
		str[i] = init_str[i];
	while (i < LEN_STR_STEPS)
		str[i++] = '\0';
}

// ____________________________________________________________________MAIN FUNC

t_all	*init(void)
{
	t_all	*all;

	all = malloc(sizeof(t_all));
	check_error(!all);
	all->mlx = mlx_init();
	all->map.next_x = 0;
	all->map.next_y = 0;
	all->my.map_x = ((WINDOW_W + 1) % 2 * BLOCK_SIZE / 2);
	all->my.map_y = ((WINDOW_H + 1) % 2 * BLOCK_SIZE / 2);
	all->num_steps = 0;
	init_str_steps(all->str_steps, "STEPS : ");
	init_pers(all);
	init_objects(all);
	return (all);
}
