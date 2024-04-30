/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:20:58 by upolat            #+#    #+#             */
/*   Updated: 2024/04/30 09:17:51 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//char	*ft_read(ssize_t bytes_read, int fd, char *buffer, char *str_static, char *str_auto, char *temp)

char	*get_next_line(int fd)
{
	static char	*str_static = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;
	ssize_t		bytes_read;
	char		*str_auto;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (str_static)
	{
		temp = ft_strchr(str_static, '\n');
		if (temp)
		{
			str_auto = ft_strdup(temp);
			temp = ft_str_tillchar(str_static, '\n');
			free(str_static);
			str_static = str_auto;
			return (temp);
		}
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		if (str_static)
			temp = ft_strjoin(str_static, buffer);
		else
			temp = ft_strdup(buffer);
		if (!temp)
			return (NULL);
		free(str_static);
		str_static = temp;
		temp = ft_strchr(str_static, '\n');
		if (temp)
		{
			str_auto = ft_strdup(temp);
			temp = ft_str_tillchar(str_static, '\n');
			free(str_static);
			str_static = str_auto;
			return (temp);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read == -1)
	{
		free(str_static);
		str_static = NULL;
		return (NULL);
	}
	//If EOF is reached and there's no newline in the remaining data
	if (str_static && *str_static != '\0')
	{
		temp = ft_strdup(str_static);
		free(str_static);
		str_static = NULL;
		return (temp);
	}
	//Clean up if we reach the end without any remaining data
	free(str_static);
	str_static = NULL;
	return (NULL);
}

#include <stdio.h>

int main(void)
{
	int		fd;
	char	*str;

	fd = open("test.txt", O_RDONLY);
	str = "hello";
	while (str)
	{
		str = get_next_line(fd);
		if (str == NULL)
			printf("NULL returned\n");
		else
			printf("%s", str);
		printf("----\n");
		free(str);
	}
	close(fd);
	return (0);
}

