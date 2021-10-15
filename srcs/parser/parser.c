/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 04:40:02 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/15 05:30:20 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/parser.h"
// #include "parser.h"

// ____________________________________________________________________MAIN FUNC

void	parser(t_all *all, char const *argv[])
{
	load_map(all, argv[1]);
	check_map(all);
	pave_the_road(&all->map);
	set_objs_on_map(all);
	draw_map(all);
	set_xy_of_map(&all->map);
}
