/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:47:46 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/07 15:39:10 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/FDF.h"

void	ordin_alloc(int **map, int fd)
{
	int 	i;
	int 	j;
	char	*line;

	i = 1;
	j =
	line = get_next_line(fd);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	j = 0;
	while ()
}

int	**parsing(char *file)
{
	int		fd;
	char	*line;
	int 	**map;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	map = ft_calloc((ft_countword(line, ' ') + 1), sizeof(int *));
	ordin_alloc();
	return (map);
}