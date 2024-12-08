/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:47:19 by emlinott          #+#    #+#             */
/*   Updated: 2024/12/08 16:52:31 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char const *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)str);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)str);
	else
		return (NULL);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*dest_start;

	dest_start = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_start);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*result;
	char	*result_p;
	char	*src;

	s1_len = 0;
	if (!s1 && !s2)
		return (NULL);
	if (s1)
		s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!result)
		return (NULL);
	result_p = result;
	src = s1;
	while (src && *src)
		*result_p++ = *src++;
	src = (char *)s2;
	while (src && *src)
		*result_p++ = *src++;
	*result_p = '\0';
	free(s1);
	return (result);
}
