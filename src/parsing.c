/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:47:46 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/20 17:07:40 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/FDF.h"

void	get_size(t_map *map, int fd)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	j = ft_countword(line, ' ');
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	map->size_y = i;
	map->size_x = j;
}

void	what_alloc(t_map *map, int fd)
{
	int	i;

	i = 0;
	get_size(map, fd);
	map->map = ft_calloc((map->size_y), sizeof(int *));
	if (!map->map)
	{
		map->size_x = 0;
		map->size_y = 0;
		clean_close(map->data);
	}
	while (i < map->size_y)
	{
		map->map[i] = ft_calloc(map->size_x, sizeof(int));
		if (!map->map[i++])
		{
			map->size_y = i - 1;
			clean_close(map->data);
		}
	}
}

void	split_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	give_values(t_map *map, int fd)
{
	int		x;
	int		y;
	char	**split_line;

	y = 0;
	while (y < map->size_y)
	{
		x = 0;
		split_line = ft_split(get_next_line(fd), ' ');
		if (!split_line)
			return (0);
		while (x < map->size_x)
		{
			map->map[y][x] = ft_atoi(split_line[x]);
			x++;
		}
		split_free(split_line);
		y++;
	}
	return (1);
}

t_map	*parsing(char *file, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		clean_close(map->data);
	what_alloc(map, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		clean_close(map->data);
	if (!give_values(map, fd))
	{
		close(fd);
		clean_close(map->data);
	}
	close(fd);
	return (map);
}
