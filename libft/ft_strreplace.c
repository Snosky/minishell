/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 17:14:05 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/22 13:19:27 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strreplace(char *search, char *replace, char *s, int rec)
{
	char	*ret;
	char	*str;
	char	*tmp;

	tmp = ft_strdup(s);
	ret = NULL;
	if ((str = ft_strstr(tmp, search)) == NULL)
		return (NULL);
	str[0] = 0;
	ret = ft_strdup(tmp);
	ret = ft_strjoin(ret, replace);
	ret = ft_strjoin(ret, str + ft_strlen(search));
	if (ft_strstr(ret, search) && rec)
		ret = ft_strreplace(search, replace, ret, 1);
	return (ret);
}
