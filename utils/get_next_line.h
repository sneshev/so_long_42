/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sneshev <sneshev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:12:47 by sneshev           #+#    #+#             */
/*   Updated: 2025/01/08 14:01:11 by sneshev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# include <unistd.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ret(char *line, char **red, char **saved, int bytes_red);
int		use_saved(char **line, char **saved);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
int		mal_red(int fd, char **red);
int		find_nl(const char *s);
char	*get_next_line(int fd);
int		use_read(int fd, char **red);
char	*add_to_line(char **line_ptr, char **red_ptr);

#endif