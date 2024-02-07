/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:43:14 by avaldin           #+#    #+#             */
/*   Updated: 2023/12/20 11:05:23 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>

char	*get_next_line(int fd);
void	ft_memmove(char *dest, char *src);
char	*ft_strjoin(size_t n, char *rt_line, char *buffer);
size_t	find_endline(char *buffer);
bool	security(size_t i, char *rt_line, char *buffer);
char	*reallo_copy(char *rt_line);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif
