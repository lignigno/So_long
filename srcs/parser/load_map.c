/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 07:01:14 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/15 08:07:44 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// _________________________________________________________________SUBFUNCTIONS

void	find_out_size_map(t_map *map, const char *file)
{
	int		readed;
	char	*line;
	ssize_t	len;
	int		fd;

	fd = open(file, O_RDONLY);
	readed = 1;
	line = NULL;
	map->width = 0;
	map->height = 0;
	while (readed)
	{
		readed = gnl(fd, &line);
		if (line)
			len = ft_strlen(line);
		check_error(readed < 0 || (len != map->width && map->width));
		free(line);
		map->width = len;
		map->height++;
	}
	close(fd);
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	translate_in_ids(t_all *all, char *line, int y)
{
	t_uint	x;

	x = 0;
	while (x < all->map.width)
	{
		if ('0' <= line[x] && line[x] <= '2')
			all->map.arr[x][y].obj_id = line[x] - '0';
		else if (line[x] == 'C')
			all->map.arr[x][y].obj_id = COLLECTIBLE;
		else if (line[x] == 'E')
			all->map.arr[x][y].obj_id = CLOSED_EXIT;
		else if (line[x] == 'P')
			all->map.arr[x][y].obj_id = PERS;
		else
			check_error(1);
		x++;
	}
}

//                                                                             |
// ----------------------------------------------------------------------------|
//                                                                             |

void	set_ids_on_map(t_all *all, const char *file)
{
	t_uint	y;
	int		fd;
	int		readed;
	char	*line;

	fd = open(file, O_RDONLY);
	y = 0;
	readed = 1;
	line = NULL;
	while (readed)
	{
		readed = gnl(fd, &line);
		check_error(readed < 0);
		translate_in_ids(all, line, y);
		free(line);
		y++;
	}
	close(fd);
}

// ____________________________________________________________________MAIN FUNC

void	load_map(t_all *all, const char *file)
{
	t_uint	i;

	find_out_size_map(&all->map, file);
	all->map.arr = malloc(all->map.width * sizeof(t_obj *));
	check_error(!all->map.arr);
	i = 0;
	while (i < all->map.width)
	{
		all->map.arr[i] = malloc(all->map.height * sizeof(t_obj));
		check_error(!all->map.arr);
		i++;
	}
	set_ids_on_map(all, file);
}
