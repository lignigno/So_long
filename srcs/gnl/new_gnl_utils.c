/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 08:13:33 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/15 08:03:39 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_realloc(char *str, int len)
{
	char	*new;
	int		i;

	if (len < ft_strlen(str))
		return (NULL);
	new = malloc(len * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

char	*join_and_realloc(char *s, char *buf, int size)
{
	int		i;
	int		j;
	int		n;

	n = ft_strlen(s);
	j = n + size + 1;
	s = ft_realloc(s, j);
	if (!s)
		return (NULL);
	i = 0;
	j = n;
	while (i < size)
	{
		s[j] = buf[i];
		i++;
		j++;
	}
	s[j] = '\0';
	return (s);
}

int	find_char_index(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
