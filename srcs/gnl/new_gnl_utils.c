/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 08:13:33 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/09 08:15:50 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen1(const char *str)
{
	const	char	*ptr;
	size_t			count;

	count = 0;
	ptr = str;
	while (*ptr)
	{
		++ptr;
		++count;
	}
	return (count);
}

char		*ft_strnew(size_t size)
{
	return (ft_memalloc((size + 1) * sizeof(char)));
}

void		*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size);
	return (ptr);
}

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned	char	*ub;

	ub = (unsigned char *)b;
	while (len > 0)
	{
		*ub = c;
		len--;
		ub++;
	}
	return (b);
}

int			ft_memdel(void **ptr)
{
	if (*ptr)
	{
		ft_memset(*ptr, 0, ft_strlen(*ptr));
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
