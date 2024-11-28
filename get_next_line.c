/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:47:34 by afaugero          #+#    #+#             */
/*   Updated: 2024/11/28 14:58:06 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 80
#endif

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*line;
	int		i;

	if (fd < 0)
		return (NULL);
	if (read(fd, buffer, BUFFER_SIZE) <= 0)
		return (NULL);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (*(buffer + i) == '\n')
			break ;
		i++;
	}
	line = ft_strndup(buffer, i);
	if (!line)
		// FREE
		return (NULL);
	return (line);
}
