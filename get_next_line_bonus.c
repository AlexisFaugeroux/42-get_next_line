/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:55:26 by afaugero          #+#    #+#             */
/*   Updated: 2024/12/19 10:27:10 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

char	*ft_join(char *buffer, char *tmp)
{
	char	*res;

	res = ft_strjoin(buffer, tmp);
	return (free(buffer), res);
}

char	*ft_read(char *buffer, int fd)
{
	char	*tmp;
	ssize_t	bytes_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(tmp), NULL);
		tmp[bytes_read] = '\0';
		buffer = ft_join(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	if (*buffer == '\0')
		return (free(buffer), free(tmp), NULL);
	return (free(tmp), buffer);
}

char	*ft_line(char *buffer)
{
	int		i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (*(buffer + i) && *(buffer + i) != '\n')
		i++;
	if (!ft_strchr(buffer, '\n'))
		return (ft_strndup(buffer, i));
	return (ft_strndup(buffer, i + 1));
}

void	*ft_memmove(char *dest, void const *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;

	if (!src || !dest)
		return (NULL);
	if (dest == src || n == 0)
		return (dest);
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	if (pdest < psrc)
	{
		while (n--)
			*(pdest++) = *(psrc++);
	}
	else
	{
		pdest += n - 1;
		psrc += n - 1;
		while (n--)
			*(pdest--) = *(psrc--);
	}
	*(dest + ft_strlen(dest)) = '\0';
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FD_SETSIZE];
	char		*line;
	ssize_t		l_len;
	ssize_t		b_len;

	if (fd < 0 || fd > FD_SETSIZE || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd] || !ft_strchr(buffer[fd], '\n'))
		buffer[fd] = ft_read(buffer[fd], fd);
	line = ft_line(buffer[fd]);
	l_len = ft_strlen(line);
	b_len = ft_strlen(buffer[fd]);
	buffer[fd] = ft_memmove(buffer[fd], buffer[fd] + l_len, b_len - l_len + 1);
	if (!buffer[fd])
		return (free(line), NULL);
	return (line);
}

/* int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	if (argc < 1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Erreur ouverture fichier\n");
		return (0);
	}
	i = 0;
	while (i < 10)
	{
		line = get_next_line(fd);
		if (line)
		{
			printf("%s", line);
			free(line);
		}
		i++;
	}
	close(fd);
} */
