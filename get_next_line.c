/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:47:34 by afaugero          #+#    #+#             */
/*   Updated: 2024/12/01 18:44:04 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*ft_read(char *line, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*res;
	ssize_t	bytes_read;

	if (!line)
		line = ft_calloc(1, 1);
	if (!line)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (NULL);
    buffer[bytes_read] = '\0';
		res = ft_strjoin(line, buffer);
		if (!res)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (res);
}

char	*ft_line(char *line)
{
	size_t	i;
  char    *res;

  printf("%s\n", line);
  i = 0;
  while (*(line + i) != '\n')
    i++;
  res = ft_strndup(line, i);
  if (!res)
  {
    free(line);
    return (NULL);
  }
  free(line);
  printf("%s\n", res);
  return (res);
}

char	*get_next_line(int fd)
{
	static char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = ft_read(line, fd);
	if (!line)
		return (NULL);
  line = ft_line(line);
  if (!line)
    return (NULL);
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc < 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Erreur ouverture fichier");
		return (0);
	}
	/* printf("Result:\n"); */
  get_next_line(fd);
	/* printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd)); */
  close(fd);
}
