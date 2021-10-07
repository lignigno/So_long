/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:26:52 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/07 03:28:35 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
#define STRUCTS_H

typedef unsigned int t_uint;

typedef struct s_cut_param
{
	t_uint	start_x;
	t_uint	start_y;
	t_uint	cut_by_x;
	t_uint	cut_by_y;
	t_uint	new_width;
	t_uint	new_height;
}				t_cut_param;

typedef struct s_imgdata
{
	int		bpp;
	void	*ptr;
	char	*addr;
	int		width;
	int		height;
	int		endian;
}				t_imgdata;

typedef struct s_pers
{
	t_uint		x;
	t_uint		y;
	int			move_x;
	int			move_y;
	t_uint		motion_frame;
	t_imgdata	*current_move;
	t_imgdata	up[4];
	t_imgdata	down[4];
	t_imgdata	left[4];
	t_imgdata	right[4];
}				t_pers;



typedef struct s_all
{
	void	*mlx;
	void	*win;
	t_pers	pers;
}				t_all;



#endif
