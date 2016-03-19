/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:44:30 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/19 16:04:26 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		ft_pwd(t_list *envlst)
{
	t_env	*pwd;

	pwd = NULL;
	if ((pwd = find_env(envlst, "PWD")))
		ft_putendl(remove_home(envlst));
	else
		ft_putendl_fd("minishell: env PWD not define", 2);
	return (1);
}
