/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strimp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 16:43:28 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/22 13:22:50 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strimp(char **tab, char *s)
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	while (tab[i])
	{
		if (i == 0)
			ret = ft_strdup(tab[i]);
		else
		{
			ret = ft_strjoin(ret, s);
			ret = ft_strjoin(ret, tab[i]);
		}
		i++;
	}
	return (ret);
}
