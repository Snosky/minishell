/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_home.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 15:56:26 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/22 13:18:35 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*remove_home(t_list *envlst, char *path)
{
	t_env	*home;

	home = find_env(envlst, "HOME");
	if (path && home && ft_strstr(path, home->value))
		return (ft_strreplace(home->value, "~", path, 0));
	else if (path && home)
		return (path);
	return (NULL);
}
