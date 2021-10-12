/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 08:12:22 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/09 08:15:13 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	ssize_t	i;

	new = ft_strnew(ft_strlen(s1));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	return (new);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != (char)c)
		if (!s[i++])
			return (NULL);
	return ((char *)&s[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL || !(ptr = (char *)malloc(ft_strlen(s1)
		+ ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s || (long int)len < 0)
		return (NULL);
	ptr = (char *)malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	while (start < ft_strlen(s) && i < len)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int		gnl(int fd, char **line)
{
	ssize_t		r;
	char		bf[BUFFER_SIZE + (r = 1)];
	static char	*lr[FD_SIZE];
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	lr[fd] == NULL ? lr[fd] = ft_strnew(0) : NULL;
	while (!ft_strchr(lr[fd], '\n') && (r = read(fd, bf, BUFFER_SIZE)) > 0)
	{
		bf[r] = '\0';
		tmp = ft_strjoin(lr[fd], bf);
		ft_memdel((void **)&lr[fd]);
		lr[fd] = tmp;
	}
	if (r == 0)
		*line = ft_strdup(lr[fd]);
	else if (r > 0)
		*line = ft_substr(lr[fd], 0, (ft_strchr(lr[fd], '\n') - lr[fd]));
	else
		return (-1);
	tmp = ft_strdup(lr[fd] + (ft_strlen(*line) + ((r > 0) ? +1 : +0)));
	ft_memdel((void **)&lr[fd]);
	lr[fd] = tmp;
	return (r == 0 ? 0 * ft_memdel((void **)&lr[fd]) : 1);
}