/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:15:53 by upolat            #+#    #+#             */
/*   Updated: 2024/05/02 14:51:33 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*helper3(char **str_static);

// Create a copy up to the newline
// Update str_static to start after the newline
int	helper1(char **str_static, char **line)
{
	char	*newline_ptr;
	char	*temp;

	newline_ptr = ft_strchr(*str_static, '\n');
	*line = NULL;
	if (newline_ptr)
	{
		*line = ft_str_tillchar(*str_static, '\n');
		if (!*line)
		{
			free(*line);
			return (0);
		}
		temp = ft_strdup(newline_ptr);
		if (!temp)
		{
			free(*line);
			return (0);
		}
		free(*str_static);
		*str_static = temp;
	}
	return (1);
}

char	*helper2(int fd, ssize_t *bytes_read, char **str_static, char *buffer)
{
	char	*temp;
	char	*line;

	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (*bytes_read > 0)
	{
		buffer[*bytes_read] = '\0';
		if (*str_static)
			temp = ft_strjoin(*str_static, buffer);
		else
			temp = ft_strdup(buffer);
		if (!temp)
			return (helper3(str_static));
		free(*str_static);
		*str_static = temp;
		if (*str_static)
		{
			if (!helper1(str_static, &line))
				return (helper3(str_static));
			if (line != NULL)
				return (line);
		}
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (NULL);
}

char	*helper3(char **str_static)
{
	free(*str_static);
	*str_static = NULL;
	return (NULL);
}

// If EOF is reached and there's no newline in the remaining data
//After if, Clean up if we reach the end without any remaining data
char	*helper4(char **str_static)
{
	char	*temp;

	if (*str_static && **str_static != '\0')
	{
		temp = ft_strdup(*str_static);
		free(*str_static);
		*str_static = NULL;
		return (temp);
	}
	free(*str_static);
	*str_static = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*str_static[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) < 0)
		return (helper3(&str_static[fd]));
	if (str_static[fd])
	{
		if (!helper1(&str_static[fd], &line))
			return (helper3(&str_static[fd]));
		if (line != NULL)
			return (line);
	}
	line = helper2(fd, &bytes_read, &str_static[fd], buffer);
	if (line != NULL)
		return (line);
	if (bytes_read == -1)
		return (helper3(&str_static[fd]));
	line = helper4(&str_static[fd]);
	if (line != NULL)
		return (line);
	return (helper3(&str_static[fd]));
}
