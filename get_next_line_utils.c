/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:03:47 by upolat            #+#    #+#             */
/*   Updated: 2024/04/28 01:07:43 by upolat           ###   ########.fr       */
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



char	*ft_str_tillchar(char *str, int c)
{
	int		i;
	char	*str_return;

	i = 0;
	str_return = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (str_return == NULL)
		return (NULL);
	while (str[i] && str[i] != (char)c)
	{
		str_return[i] = str[i];
		i++;
	}
	str_return[i] = str[i];
	i++;
	while (str[i])
		str_return[i++] = '\0';
	str_return[i] = '\0';
	free(str);
	return (str_return);
}
/*
char	*ft_str_tillchar(char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != (char)c)
		i++;
	i++;
	while (str[i])
		str[i++] = '\0';
	return (str);
}

char *ft_str_tillchar(char *str, int c) {
    int i = 0;
    char *str_return;

    str_return = malloc(sizeof(char) * (ft_strlen(str) + 1));
    if (str_return == NULL)
        return (NULL);

    while (str[i] && str[i] != (char)c) {
        str_return[i] = str[i];
        i++;
    }
    str_return[i] = '\0'; // Correctly terminate the string

    return str_return;
}
*/
