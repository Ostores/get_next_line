/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 16:32:48 by emlinott          #+#    #+#             */
/*   Updated: 2024/12/08 16:57:16 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

// libft \\ 

size_t			ft_strlen(char const *str);
char			*ft_strchr(char const *str, int c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strjoin(char *s1, char const *s2);

// get next line \\ 

char			*get_next_line(int fd);

#endif
