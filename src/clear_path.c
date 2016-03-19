/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:39:39 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/19 17:28:32 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*clear_back_path(char *pwd, int y)
{
	char	**split;
	char	*ret;
	int		i;

	split = ft_strsplit(pwd, '/');
	ret = ft_strnew(0);
	i = 0;
	while (split[i])
	{
		y = 1;
		while (split[i + y] && ft_strcmp(split[i + y], ".") == 0)
			y++;
		if (ft_strcmp(split[i], "..") &&
			((split[i + y] && ft_strcmp(split[i + y], "..")) || !split[i + 1]))
			if (ft_strcmp(split[i], ""))
			{
				ret = ft_strjoin(ret, "/");
				ret = ft_strjoin(ret, split[i]);
				y = (y <= 1) ? 1 : y - 1;
			}
		i += y;
	}
	if (ft_strcmp(ret, "") == 0)
		return ("/");
	return (ret);
}

char		*clear_path(char *pwd)
{
	if (ft_strstr(pwd, ".."))
		pwd = clear_back_path(pwd, 1);
	return (pwd);
}
