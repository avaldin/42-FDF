/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:49:05 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/20 17:10:42 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/FDF.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		exit(EXIT_FAILURE);
	data->mlx = NULL;
	data->img = NULL;
	data->map = NULL;
	data->mlx = malloc(sizeof(t_mlx));
	data->img = malloc(sizeof(t_img));
	data->map = malloc(sizeof(t_map));
	if (!data->mlx || !data->img || !data->map)
		clean_close(data);
	data->mlx->data = data;
	data->img->data = data;
	data->img->img = NULL;
	data->img->addr = NULL;
	data->mlx->ptr = NULL;
	data->mlx->win = NULL;
	data->map->map = NULL;
	data->map->point = NULL;
	data->map->range = NULL;
	data->map->data = data;
	return (data);
}

void	map_free(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size_y)
		free(map->map[i++]);
	if (map->point)
		free(map->point);
	if (map->range)
		free(map->range);
	free(map->map);
}

int	clean_close(t_data *data)
{
	if (data->mlx)
	{
		if (data->img->img)
			mlx_destroy_image(data->mlx->ptr, data->img->img);
		if (data->mlx->win)
			mlx_destroy_window(data->mlx->ptr, data->mlx->win);
		if (data->mlx->ptr)
			mlx_destroy_display(data->mlx->ptr);
		if (data->mlx->ptr)
			free(data->mlx->ptr);
		free(data->mlx);
	}
	if (data->img)
		free(data->img);
	if (data->map)
	{
		if (data->map->map)
			map_free(data->map);
		free(data->map);
	}
	if (data)
		free(data);
	exit(EXIT_SUCCESS);
	return (0);
}

void	clean_open(t_data *data)
{
	data->mlx->ptr = mlx_init();
	if (!data->mlx->ptr)
		clean_close(data);
	data->mlx->win = mlx_new_window(data->mlx->ptr, 3840, 2160, "fdf");
	if (!data->mlx->win)
		clean_close(data);
	data->img->img = mlx_new_image(data->mlx->ptr, 3840, 2160);
	if (!data->img->img)
		clean_close(data);
	data->img->addr = mlx_get_data_addr(data->img->img,
			&data->img->bits_per_pixel,
			&data->img->line_length, &data->img->endian);
}
