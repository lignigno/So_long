/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lignigno <lignign@student.21-school.ru>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 08:14:07 by lignigno          #+#    #+#             */
/*   Updated: 2021/10/15 08:04:55 by lignigno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef FD_MAX
#  define FD_MAX 256
# endif

typedef struct s_buffer
{
	int		size;
	char	content[BUFFER_SIZE + 1];
}			t_buffer;

char	*join_and_realloc(char *s, char *buf, int size);
int		find_char_index(char *str, char c);
int		get_next_line(int fd, char **line);

#endif