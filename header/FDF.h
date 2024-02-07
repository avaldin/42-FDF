/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:28:50 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/02 11:06:00 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct	s_mlx {
	void	*ptr;
	void	*win;
	void	*data;
}				t_mlx;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*data;
}				t_img;

typedef struct	s_data
{
	t_mlx	*mlx;
	t_img	*img;
}				t_data;

# include "../mlx_linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	init_data(t_data *data);
void	clean_close(t_data *data);
void	clean_open(t_data *data);



#endif
