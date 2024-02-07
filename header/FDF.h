/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:28:50 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/07 13:53:11 by avaldin          ###   ########.fr       */
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
	int		**map;
}				t_data;

# include "../mlx_linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
#include <X11/X.h>


t_data	*init_data(void);
int		clean_close(t_data *data);
void	clean_open(t_data *data);



#endif
