/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:29:08 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/20 16:47:58 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/FDF.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
		clean_close(data);
	return (0);
}

void	ft_hook(t_data *data)
{
	mlx_hook(data->mlx->win, 17, NoEventMask, clean_close, data);
	mlx_hook(data->mlx->win, KeyPress, KeyPressMask, key_hook, data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		return (0);
	data = NULL;
	data = init_data();
	data->map = parsing(argv[1], data->map);
	if (!data->map)
		clean_close(data);
	clean_open(data);
	create_img(data->map, data->img, data->mlx);
	ft_hook(data);
	mlx_loop(data->mlx->ptr);
	return (0);
}
