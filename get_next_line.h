/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaugero <afaugero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:47:11 by afaugero          #+#    #+#             */
/*   Updated: 2024/12/19 10:28:30 by afaugero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 80
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char const *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strndup(char *src, size_t n);
char	*ft_strchr(char const *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
