/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 18:01:48 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/22 12:48:03 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	err_ft_env(char *s)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(s, 2);
	ft_putendl_fd(": No such file or directory", 2);
	return (1);
}

int			ft_env(t_list *envlst, char **args)
{
	t_list	*tmp;
	t_env	*env;

	tmp = envlst;
	if (args[1] != NULL)
		return (err_ft_env(args[1]));
	while (tmp)
	{
		env = (t_env *)tmp->content;
		ft_putstr(env->key);
		ft_putchar('=');
		ft_putendl(env->value);
		tmp = tmp->next;
	}
	return (1);
}
