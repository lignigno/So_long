/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:22:24 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/15 08:56:41 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/public.h"

static void	check_extention(char const *argv[])
{
	size_t	len;

	len = ft_strlen(argv[1]);
	check_error(len < 5
		|| argv[1][len - 1] != 'r'
		|| argv[1][len - 2] != 'e'
		|| argv[1][len - 3] != 'b'
		|| argv[1][len - 4] != '.');
}

// ____________________________________________________________________MAIN FUNC

int	main(int argc, char const *argv[])
{
	t_all	*all;

	check_error(argc != 2);
	check_extention(argv);
	all = init();
	parser(all, argv);
	all->win = mlx_new_window(all->mlx, WINDOW_W * BLOCK_SIZE,
			WINDOW_H * BLOCK_SIZE, "UnicornGameS :)");
	printf("%s0\n", all->str_steps);
	mlx_hook(all->win, 2, 0, key_press, all);
	mlx_hook(all->win, 3, 0, key_release, all);
	mlx_hook(all->win, 17, 0, end_game, all);
	mlx_loop_hook(all->mlx, move_management, all);
	mlx_loop(all->mlx);
	return (0);
}
