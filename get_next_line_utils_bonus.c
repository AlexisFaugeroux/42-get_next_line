/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:41:08 by afaugero          #+#    #+#             */
/*   Updated: 2024/12/19 10:27:38 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stddef.h>

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (*(str + i))
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	total;
	size_t	i;

	if (size != 0 && nmemb > ((size_t)-1) / size)
		return (NULL);
	total = size * nmemb;
	alloc = (void *)malloc(total);
	if (!alloc)
		return (NULL);
	i = 0;
	while (i < total)
	{
		*((char *)(alloc + i)) = '\0';
		i++;
	}
	return (alloc);
}

char	*ft_strndup(char *src, size_t n)
{
	size_t	i;
	char	*dup;

	if (!src)
		return (NULL);
	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (*(src + i) && i < n)
	{
		*(dup + i) = *(src + i);
		i++;
	}
	*(dup + i) = '\0';
	return (dup);
}

char	*ft_strchr(char const *s, int c)
{
	int		i;
	char	search;
	char	*ptr;

	if (!s)
		return (NULL);
	search = (char)c;
	ptr = (char *)s;
	i = 0;
	while (*(ptr + i))
	{
		if (*(ptr + i) == search)
			return (ptr + i);
		i++;
	}
	if (search == '\0')
		return (ptr + i);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t const	len = ft_strlen(s1) + ft_strlen(s2);
	size_t			i;
	size_t			j;
	char			*strjoin;

	if (s1 || s2)
	{
		if (!s1)
			return (s2);
		if (!s2)
			return (s1);
		strjoin = (char *)malloc(sizeof(char) * (len + 1));
		if (!strjoin)
			return (NULL);
		i = -1;
		while (*(s1 + ++i))
			*(strjoin + i) = *(s1 + i);
		j = -1;
		while (*(s2 + ++j))
			*(strjoin + i++) = *(s2 + j);
		*(strjoin + len) = '\0';
		return (strjoin);
	}
	return (NULL);
}
