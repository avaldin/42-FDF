/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:49:05 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/07 13:53:58 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/FDF.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->mlx = malloc(sizeof(t_mlx));
	data->img = malloc(sizeof(t_img));
	data->mlx->data = data;
	data->img->data = data;
	data->img->img = NULL;
	data->img->addr = NULL;
	data->mlx->ptr = NULL;
	data->mlx->win = NULL;
	data->map = NULL;
	return (data);
}

int	clean_close(t_data *data)
{
	if (data->img->img)
		mlx_destroy_image(data->mlx->ptr, data->img->img);
	if (data->mlx->win)
		mlx_destroy_window(data->mlx->ptr, data->mlx->win);
	if (data->mlx->ptr)
		mlx_destroy_display(data->mlx->ptr);
	if (data->mlx->ptr)
		free(data->mlx->ptr);
	if (data->mlx)
		free(data->mlx);
	if (data->img)
		free(data->img);
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
	data->mlx->win = mlx_new_window(data->mlx->ptr, 1920, 1080, "fdf");
	if (!data->mlx->win)
		clean_close(data);
	data->img->img = mlx_new_image(data->mlx->ptr, 1920, 1080);
	if (!data->img->img)
		clean_close(data);
}