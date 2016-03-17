/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 21:30:06 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/17 15:54:39 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	prompt(t_list *envlst)
{
	t_env	*pwd;
	t_env	*home;

	pwd = find_env(envlst, "PWD");
	home = find_env(envlst, "HOME");
	ft_putstr("\e[0;36m");
	ft_putchar('[');
	if (pwd && home && ft_strstr(pwd->value, home->value))
	{
		ft_putchar('~');
		ft_putstr(ft_strstr(pwd->value, home->value) + ft_strlen(home->value));
	}
	else if (pwd)
		ft_putstr(pwd->value);
	else
		ft_putstr("minishell");
	ft_putchar(']');
	ft_putstr("\e[1;32m");
	ft_putchar('$');
	ft_putstr("\e[0;37m");
	ft_putchar(' ');
}
