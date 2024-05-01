/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:15:53 by upolat            #+#    #+#             */
/*   Updated: 2024/05/01 16:36:17 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Create a copy up to the newline
// Update str_static to start after the newline
char	*helper1(char **str_static)
{
	char	*newline_ptr;
	char	*result;
	char	*temp;

	newline_ptr = ft_strchr(*str_static, '\n');
	result = NULL;
	if (newline_ptr)
	{
		result = ft_str_tillchar(*str_static, '\n');
		temp = ft_strdup(newline_ptr);
		free(*str_static);
		*str_static = temp;
	}
	return (result);
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
			return (NULL);
		free(*str_static);
		*str_static = temp;
		if (*str_static)
		{
			line = helper1(str_static);
			if (line != NULL)
				return (line);
		}
		*bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (NULL);
}

//If EOF is reached and there's no newline in the remaining data
//After if, Clean up if we reach the end without any remaining data
char	*helper3(char **str_static)
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

void	helper4(char **str_static)
{
	free(*str_static);
	*str_static = NULL;
}

char	*get_next_line(int fd)
{
	static char	*str_static[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (str_static[fd])
	{
		line = helper1(&str_static[fd]);
		if (line != NULL)
			return (line);
	}
	line = helper2(fd, &bytes_read, &str_static[fd], buffer);
	if (line != NULL)
		return (line);
	if (bytes_read == -1)
	{
		helper4(&str_static[fd]);
		return (NULL);
	}
	line = helper3(&str_static[fd]);
	if (line != NULL)
		return (line);
	return (NULL);
}