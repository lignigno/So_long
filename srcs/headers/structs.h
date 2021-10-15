/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:26:52 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/15 05:54:53 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# define LEN_STR_STEPS 29

typedef unsigned int	t_uint;

enum	e_objects_id
{
	GROUND,
	WALL,
	ROAD,
	COLLECTIBLE,
	CLOSED_EXIT,
	WATER,
	UP_GROUND,
	DOWN_GROUND,
	OPENED_EXIT,
	NUMBER_OBJECTS,
	PERS,
	DIE = 666,
	FINISH = 777,
};

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
	ssize_t		x;
	ssize_t		y;
	t_uint		motion_frame;
	t_imgdata	*current_move;
	t_imgdata	up[4];
	t_imgdata	down[4];
	t_imgdata	left[4];
	t_imgdata	right[4];
}				t_pers;

typedef struct s_obj
{
	int			obj_id;
	t_imgdata	texture;
}				t_obj;

typedef struct s_map
{
	ssize_t		x;
	ssize_t		y;
	ssize_t		next_x;
	ssize_t		next_y;
	int			move_x;
	int			move_y;
	t_imgdata	back;
	ssize_t		width;
	ssize_t		height;
	t_obj		**arr;
}				t_map;

typedef struct s_fpsc
{
	size_t	frame_update;
}				t_fpsc;

typedef struct s_myconst
{
	ssize_t	map_x;
	ssize_t	map_y;
}				t_myconst;

typedef struct s_all
{
	void		*win;
	void		*mlx;
	size_t		num_steps;
	char		str_steps[LEN_STR_STEPS];
	t_fpsc		timer;
	t_uint		num_items;
	t_myconst	my;
	t_pers		*pers;
	t_imgdata	objs[NUMBER_OBJECTS];
	t_map		map;
}				t_all;

#endif
