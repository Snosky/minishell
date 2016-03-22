/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 17:14:03 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/22 13:23:06 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		wc(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j++;
			while (s[i] != c)
			{
				if (!s[i])
					return (j);
				i++;
			}
		}
		i++;
	}
	return (j);
}

static int		wl(const char *s, int i, char c)
{
	int	j;

	j = 0;
	while (s[i] != c && s[i])
	{
		i++;
		j++;
	}
	return (j);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**ret;
	int		i;
	int		k;
	int		w;

	if (!s)
		return (0);
	w = wc(s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * w + 1)))
		return (NULL);
	i = 0;
	k = 0;
	ret[w] = NULL;
	while (k < w)
	{
		while (s[i] == c)
			i++;
		ret[k] = ft_strsub(s, i, wl(s, i, c));
		while (s[i] && s[i] != c)
			i++;
		k++;
	}
	return (ret);
}
