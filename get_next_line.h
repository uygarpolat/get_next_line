/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 08:30:20 by upolat            #+#    #+#             */
/*   Updated: 2024/05/06 16:14:57 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 101
# endif

// get_next_line.c
char	*get_next_line(int fd);
char	*process_remaining_data(char **str_static);
char	*clean_up_static(char **str_static);
char	*read_and_process(int fd, ssize_t *bytes_read,
			char **str_static, char *buffer);
int		extract_line_and_update_static(char **str_static, char **line);

// get_next_line_utils.c
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *str);
char	*ft_str_tillchar(char *str, int c);

#endif
