/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:28:50 by upolat            #+#    #+#             */
/*   Updated: 2024/04/28 01:07:37 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*str_static;
	char		*str_auto;
	ssize_t		bytes_read;

	bytes_read = 1;
	if (str_static == NULL)
		str_static = ft_strdup("");
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = '\0';
		//printf("%zu\n", bytes_read);
		//while (bytes_read < BUFFER_SIZE + 1 && bytes_read != 0)
		//{
		//	buffer[bytes_read] = '\0';
		//	bytes_read++;
		//}
		if (bytes_read == 0)
			return (NULL);
		str_auto = ft_strjoin(str_static, buffer);
		if (str_auto == NULL)
			return (NULL);
		//if (ft_strlen(str_static) != 0)
		free(str_static);
		if (ft_strchr(str_auto, '\n'))
		{
			str_static = ft_strdup(ft_strchr(str_auto, '\n'));
			return (ft_str_tillchar(str_auto, '\n'));
		}
		else
			str_static = ft_strdup(str_auto);
		free(str_auto);
	}
	return (str_static);
}


#include <stdio.h>

int main(void)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	while (i++ < 1000)
	{
		str = get_next_line(fd);
		printf("%s", str);
		//free(str);
	}
	close(fd);
	return (0);
}
