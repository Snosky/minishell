/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 21:30:06 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/11 22:00:58 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	prompt(t_list *envlst)
{
	char	*pwd;
	char	*home;

	pwd = ft_strdup(find_env(envlst, "PWD")->value);
	home = ft_strdup(find_env(envlst, "HOME")->value);

	ft_putstr("\e[0;36m");
	ft_putchar('[');
	if (ft_strstr(pwd, home))
	{
		ft_putchar('~');
		ft_putstr(ft_strstr(pwd, home) + ft_strlen(home));
	}
	else
		ft_putstr(pwd);
	ft_putchar(']');
	ft_putstr("\e[1;32m");
	ft_putchar('$');
	ft_putstr("\e[0;37m");
	ft_putchar(' ');
}
