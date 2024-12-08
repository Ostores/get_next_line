/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlinott <emlinott@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:50:28 by emlinott          #+#    #+#             */
/*   Updated: 2024/12/08 16:58:53 by emlinott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_find_break(char *str, size_t i)
{
	char	*p;

	p = &str[i];
	while (*p && *p != '\n')
		p++;
	if (*p == '\n')
		p++;
	return (p - str);
}

static char	*ft_after_nl(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*str)
		return (free(str), NULL);
	i = ft_find_break(str, i);
	new_str = (char *)malloc((ft_strlen(str) - i) + 1);
	if (!new_str)
		return (free(new_str), NULL);
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	if (!*new_str)
		return (free(str), free(new_str), NULL);
	free(str);
	return (new_str);
}

static char	*ft_befor_nl(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str || *str == '\0')
		return (NULL);
	i = ft_find_break(str, i);
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*free_and_null(char *s1, char *s2)
{
	free(s1);
	free(s2);
	s2 = NULL;
	return (s2);
}

char	*get_next_line(int fd)
{
	int			i;
	char		*stock;
	static char	*buffer;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	stock = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!stock)
		return (NULL);
	while (!(ft_strchr(buffer, '\n')) && i != 0)
	{
		i = read(fd, stock, BUFFER_SIZE);
		if (i == -1)
		{
			buffer = free_and_null(stock, buffer);
			return (NULL);
		}
		stock[i] = '\0';
		buffer = ft_strjoin(buffer, stock);
	}
	free(stock);
	stock = ft_befor_nl(buffer);
	buffer = ft_after_nl(buffer);
	return (stock);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int i;

// 	i = 0;
// 	fd = open("42.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break ;
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return (0);
// }
