/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:28:50 by upolat            #+#    #+#             */
/*   Updated: 2024/04/25 10:37:13 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd);
{
	char	buffer[1];
	char	*str;
	size_t	i;
	size_t	bytes_read;
	size_t	len;

	len = 0;
	while (read(fd, buffer, 1) > 0 && *buffer != '\n')
		len++;
	str = malloc(sizeof(char) * (len + 1));
	return (len);
}

#include <stdio.h>

int main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("Characters until the first tab: %zu.\n", get_next_newline_char(fd));
	return (0);
}
