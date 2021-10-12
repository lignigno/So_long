/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 07:01:36 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/12 03:52:09 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
#define PARSER_H

#include "public.h"

void	load_map(t_all *all, const char *file);
void	check_map(t_all *all);
void	draw_map(t_all *all);
void	pave_the_road(t_map *map);
void	set_objs_on_map(t_all *all);
void	set_xy_of_map(t_map *map);

#endif