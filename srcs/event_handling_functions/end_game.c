/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:37:32 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/06 16:23:31 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "public.h"

// ____________________________________________________________________MAIN FUNC

int	end_game(t_all *all)
{
	(void)all;
	printf("%sBye Bye ;)%s\n", TXTC_BLUE, UNSET);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
