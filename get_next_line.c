/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:28:50 by upolat            #+#    #+#             */
/*   Updated: 2024/04/25 12:58:36 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (0);
}

size_t	get_next_line(int fd)
{
	const char		buffer[BUFFER_SIZE];
	//char		*str;
	size_t		i;
	//size_t		bytes_read;;
	size_t	len;

	i = 0;
	len = 0;
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		if (ft_strchr(buffer, '\n'))
			len++;
	}
	//str = malloc(sizeof(char) * (len + 1));
	return (len);
}

#include <stdio.h>

int main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("Characters until the first tab: %zu.\n", get_next_line(fd));
	printf("Characters until the second tab: %zu.\n", get_next_line(fd));
	return (0);
}
