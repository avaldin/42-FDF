/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:11:30 by avaldin           #+#    #+#             */
/*   Updated: 2023/12/20 11:01:23 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/get_next_line.h"

void	*ft_callloc(size_t nmemb, size_t size, char *tofree)
{
	char	*str;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (SIZE_MAX / size < nmemb)
		return (NULL);
	str = (char *)malloc(nmemb * size);
	if (!str)
	{
		if (tofree)
			free(tofree);
		return (NULL);
	}
	while (i < nmemb * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char	*ft_strjoin(size_t n, char *rt_line, char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str = ft_callloc((BUFFER_SIZE * (n + 1) + 1), sizeof(char), rt_line);
	if (!str)
		return (NULL);
	while (n && rt_line[i])
	{
		str[i] = rt_line[i];
		i++;
	}
	while (buffer[j] && buffer[j] != '\n')
	{
		str[i + j] = buffer[j];
		j++;
	}
	str[i + j] = buffer[j];
	if (rt_line)
		free(rt_line);
	return (str);
}

void	ft_memmove(char *dest, char *src)
{
	size_t	i;

	if (src)
	{
		i = 0;
		while (src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i++] = 0;
		while (i < BUFFER_SIZE && dest[i])
			dest[i++] = 0;
	}
}

size_t	find_endline(char *buffer)
{
	size_t	end;

	end = 0;
	while (buffer[end] != '\n' && buffer[end])
		end++;
	if (!buffer[end] && end)
		return (end - 1);
	return (end);
}

bool	security(size_t i, char *rt_line, char *buffer)
{
	int	j;

	j = 0;
	if (!(i + 1) || (!i && !rt_line))
	{
		if (rt_line)
			free(rt_line);
		while (buffer[j])
			buffer[j++] = 0;
		return (true);
	}
	return (false);
}
