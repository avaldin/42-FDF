/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:47:46 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/07 15:08:33 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/FDF.h"

int	**parsing(char *file)
{
	int		fd;
	char	*line;
	int 	**map;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	strlen
	return (NULL);
}