/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:36:30 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/07 03:48:04 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/public.h"
// #include "public.h"

// ____________________________________________________________________MAIN FUNC

void	rendering(t_all *all)
{
	usleep(65000);
	mlx_clear_window(all->mlx, all->win);
	mlx_put_image_to_window(all->mlx, all->win,
							all->pers.current_move[all->pers.motion_frame].ptr,
							all->pers.x, all->pers.y);
}
