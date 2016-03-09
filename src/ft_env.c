/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 18:01:48 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/09 18:05:26 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		ft_env(t_list *envlst)
{
	t_list	*tmp;
	t_env	*env;

	tmp = envlst;
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
