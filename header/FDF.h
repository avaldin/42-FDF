/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:28:50 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/21 14:03:01 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include "get_next_line.h"
# include <math.h>

typedef struct s_point
{
	int		*coord;
	int		*next;
	int		delta[2];
	int		increment[2];
	int		error[2];
}				t_point;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*data;
}				t_mlx;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*data;
}				t_img;

typedef struct s_map
{
	int		**map;
	t_point	*point;
	int		size_x;
	int		size_y;
	int		*range;
	void	*data;
}				t_map;

typedef struct s_data
{
	t_mlx	*mlx;
	t_img	*img;
	t_map	*map;
	char 	*file;
}				t_data;

t_data	*init_data(void);
int		clean_close(t_data *data);
void	clean_open(t_data *data);
t_map	*parsing(char *file, t_map *map);

void	create_img(t_map *map, t_img *img, t_mlx *mlx);
int		*projection(int x, int y, int z, t_map *map);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
t_point	*init_point(int x, int y, t_map *map, bool i);
void	connect_points(t_point *point, t_img *img);
void	tracing(int x, int y, t_map *map, t_img *img);

char	**ft_split(char *s, char c);
int		ft_countword(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(const char *nptr);

#endif
