/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaldin <avaldin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:08:04 by avaldin           #+#    #+#             */
/*   Updated: 2024/02/09 10:43:03 by avaldin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/FDF.h"

int	ft_countword(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (s[0] == '\0' || s == NULL)
		return (0);
	if (s[i] != c)
		count++;
	i++;
	while (s[i] && s[i] != '\n')
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static char	*ft_addword(const char *s, char c, int *i)
{
	int		j;
	int		p;
	char	*str;

	p = *i;
	j = 0;
	while (s[p + j] != c && s[p + j])
		j++;
	str = ft_substr(s, *i, j);
	*i = *i + j;
	return (str);
}

static char	**ft_freeee(char **str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		n;
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((ft_countword(s, c) + 1) * sizeof(char *));
	i = 0;
	n = 0;
	if (!split)
		return (NULL);
	while (n < ft_countword(s, c))
	{
		if (s[i] != c)
		{
			split[n++] = ft_addword(s, c, &i);
			if (!split[n - 1])
				return (ft_freeee(split, n - 1));
		}
		else
			i++;
	}
	free(s);
	split[n] = NULL;
	return (split);
}
