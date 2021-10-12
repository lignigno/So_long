/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 05:44:21 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/09 05:46:29 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "public.h"

// ____________________________________________________________________MAIN FUNC

void	check_error(unsigned int error_condition)
{
	if (error_condition)
	{
		perror("Error\n");
		exit(EXIT_FAILURE);
	}
}
