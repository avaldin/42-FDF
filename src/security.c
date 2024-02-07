/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:49:05 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/05 12:10:55 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/FDF.h"

void	init_data(t_data *data)
{
	data->mlx->data = data;
	data->img->data = data;
	data->img->img = NULL;
	data->img->addr = NULL;
	data->mlx->ptr = NULL;
	data->mlx->win = NULL;
}

void	clean_close(t_data *data)
{
	if (data->img->img)
		free(data->img->img);
	if (data->img->addr)
		free(data->img->addr);
	if (data->mlx->ptr)
		free(data->mlx->ptr);
	if (data->mlx->win)
		free(data->mlx->win);
}

void	clean_open(t_data *data)
{
	data->mlx->ptr = mlx_init();
	if (!data->mlx->ptr)
		clean_close(data);
	data->mlx->win = mlx_new_window(data->mlx->ptr, 1920, 1080, "fdf");
	if (!data->mlx->win)
		clean_close(data);
	data->img->img = mlx_new_image(data->mlx->ptr, 1920, 1080);
	if (!data->img->img)
		clean_close(data);
}