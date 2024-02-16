/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:33:25 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/07 15:34:29 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/FDF.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;
	size_t	i;

	i = 0;
	if (!nmemb || !size)
		return (malloc(0));
	if (SIZE_MAX / size < nmemb)
		return (NULL);
	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	while (i < nmemb * size)
		((char *)str)[i++] = 0;
	return (str);
}
