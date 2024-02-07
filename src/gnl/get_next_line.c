/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:45:41 by avaldin           #+#    #+#             */
/*   Updated: 2023/12/20 11:11:22 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*rt_line;
	size_t		i;
	size_t		n_buff_size;

	rt_line = NULL;
	n_buff_size = 0;
	while (42)
	{
		if (!buffer[0])
		{
			i = read(fd, buffer, BUFFER_SIZE);
			if (security(i, rt_line, buffer))
				return (NULL);
			buffer[BUFFER_SIZE] = '\0';
		}
		if (rt_line && (rt_line[find_endline(rt_line)] == '\n' || !i))
			return (reallo_copy(rt_line));
		i = find_endline(buffer);
		rt_line = ft_strjoin(n_buff_size++, rt_line, buffer);
		ft_memmove(buffer, &buffer[i + 1]);
		if (!rt_line || rt_line[find_endline(rt_line)] == '\n')
			return (reallo_copy(rt_line));
	}
}

char	*reallo_copy(char *rt_line)
{
	char	*str;
	size_t	i;

	i = 0;
	str = NULL;
	if (rt_line)
	{
		while (rt_line[i])
			i++;
		str = malloc((i + 1) * sizeof(char));
		if (!str)
		{
			free(rt_line);
			return (NULL);
		}
		i = 0;
		while (rt_line[i])
		{
			str[i] = rt_line[i];
			i++;
		}
		str[i] = rt_line[i];
	}
	free(rt_line);
	return (str);
}
