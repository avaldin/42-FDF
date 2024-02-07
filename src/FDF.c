/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:29:08 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/07 13:55:50 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/FDF.h"

//void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//	char	*dst;
//
//	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}

int	key_hook(int keycode, t_data *data)
{
	printf("keycode = %d\n", keycode);
	if (keycode == 65307 )
		clean_close(data);
	printf("oui\n");
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

	(void)argc;
	data = NULL;
	data = init_data();
	data->map = parsing(argv[1]);
	clean_open(data);
	//creat_img(??);
	ft_hook(data);
	mlx_loop(data->mlx->ptr);

	return (0);

//	mlx_put_image_to_window(data.mlx->ptr, data.mlx->win, data.img->img, 0, 0);
//	mlx_hook(data.mlx->win, key_hook, data.img);
//	mlx_hook(data.mlx->win, close_mlx, data.mlx);
}


//    FAIRE DES CARRE

//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
//	while (x++ < 1080)
//	{
//		y = 0;
//		while (y++ < 500)
//			my_mlx_pixel_put(&img, x, y, 0x00FF0000);
//	}