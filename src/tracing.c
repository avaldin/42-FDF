/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:27:47 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/16 15:42:39 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/FDF.h"

t_point	*init_point(int x, int y, t_map *map, bool i)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		clean_close(map->data);
	if (i)
		point->next = projection(x + 1, y, map->map[y][x + 1], map);
	else
		point->next = projection(x, y + 1, map->map[y + 1][x], map);
	point->coord = projection(x, y, map->map[y][x], map);
	point->delta[0] = abs(point->next[0] - point->coord[0]);
	point->delta[1] = -abs(point->next[1] - point->coord[1]);
	point->increment[0] = point->next[0] > point->coord[0] ? 1 : -1;
	point->increment[1] = point->next[1] > point->coord[1] ? 1 : -1;
	point->error[0] = point->delta[0] + point->delta[1];
	return (point);
}

void	tracing(int x, int y, t_map *map, t_img *img)
{
	if (x < map->size_x - 1)
	{
		map->point = init_point(x, y, map, 1);
		connect_points(map->point, img);
		free(map->point->next);
		free(map->point->coord);
		free(map->point);
		map->point = NULL;
	}
	if (y < map->size_y - 1)
	{
		map->point = init_point(x, y, map, 0);
		connect_points(map->point, img);
		free(map->point->next);
		free(map->point->coord);
		free(map->point);
		map->point = NULL;
	}
}

void	connect_points(t_point *point, t_img *img)
{
	while ((point->coord[0] != point->next[0] || point->coord[1] != point->next[1]))
	{
		my_mlx_pixel_put(img, point->coord[0], point->coord[1], 0x00FFFFFF);
		point->error[1] = 2 * point->error[0];
		if (point->error[1] >= point->delta[1])
		{
			point->error[0] += point->delta[1];
			point->coord[0] += point->increment[0];
		}
		if (point->error[1] <= point->delta[0])
		{
			point->error[0] += point->delta[0];
			point->coord[1] += point->increment[1];
		}
	}

}
