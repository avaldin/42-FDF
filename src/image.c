/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:23:09 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/16 15:42:17 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/FDF.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	*ratio_z(int **map, int size_x, int size_y)
{
	int	i;
	int	j;
	int	*range;

	i = 0;
	range = malloc(2 * sizeof(int));
	if (!range)
		return (NULL);
	range[1] = map[0][0];
	range[0] = range[1];
	while (i < size_y)
	{
		j = 0;
		while (j < size_x)
		{
			if (range[1] < map[i][j])
				range[1] = map[i][j];
			if (range[0] > map[i][j])
				range[0] = map[i][j];
			j++;
		}
		i++;
	}
	return (range);
}

int	*projection(int x, int y, int z, t_map *map)
{
	int		*proj;
	int		diff;
	float	temp;

	proj = malloc(sizeof(int) * 2);
	if (!proj)
		clean_close(map->data);
	diff = map->range[1] - map->range[0];
	x = 1200 + (1920 / map->size_x + 1) * x;
	y = 480 + (1080 / map->size_y + 1) * y;
	if (diff < 51)
		z = (6 - diff / 10) * z;
	if (diff > 500)
		z = 400 * z / diff;
	temp = (sqrtf(2) / 2) * (float )(x - y);
	proj[0] = 1000 + (int )temp;
	temp = (sqrtf((float)2 / (float)3)
			* (float )z) - ((float)1 / sqrtf(6)) * (float )(x + y);
	proj[1] = -(int )temp - 300;
	return (proj);
}

void	create_img(t_map *map, t_img *img, t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	map->range = ratio_z(map->map, map->size_x, map->size_y);
	if (!map->range)
		clean_close(map->data);
	while (y < map->size_y)
	{
		x = 0;
		while (x < map->size_x)
		{
			tracing(x, y, map, img);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, img->img, 0, 0);
}
