/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:28:50 by upolat            #+#    #+#             */
/*   Updated: 2024/04/26 16:41:47 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)(str + 1));
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	//free(s1);
	return (str);
}

char	*ft_strdup(char *str)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i])
		i++;
	word = malloc(sizeof(char) * (i + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

#include <stdio.h>

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*str_before_nl;
	static char	*str_after_nl;
	char		*temp;
	
	str_before_nl = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (str_before_nl == NULL)	
		return (NULL);
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		if (ft_strchr(buffer, '\n'))
		{
			str_after_nl = malloc(sizeof(char) * (ft_strlen(ft_strchr(buffer, '\n')) + 1));
			printf("Str length after nl is: %zu\n", ft_strlen(ft_strchr(buffer, '\n')));
			printf("Str after nl is: %s\n", ft_strchr(buffer, '\n'));
			if (str_after_nl == NULL)
				return (NULL);
			str_after_nl = ft_strchr(buffer, '\n');
			str_after_nl[ft_strlen(ft_strchr(buffer, '\n'))] = '\0';
			return ((char *)str_after_nl);
			break ;
		}
		else
		{
			printf("first str_before_nl: %s\n", str_before_nl);
			temp = ft_strdup(str_before_nl);
			printf("first temp: %s\n", temp);
			free(str_before_nl);
			str_before_nl = ft_strjoin(temp, buffer);
			printf("second str_before_nl: %s\n", str_before_nl);
			printf("-----\n");
			free(temp);
			break ;
		}
	}
	return (NULL);
}

#include <stdio.h>

int main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	//get_next_line(fd);
	return (0);
}
