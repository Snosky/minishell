/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 17:29:06 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/09 17:35:49 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_env	*find_env(t_list *envlist, char *key)
{
	t_list	*tmp;
	t_env	*env;

	tmp = envlist;
	while (tmp)
	{
		env = (t_env *)tmp->content;
		if (ft_strcmp(env->key, key) == 0)
			return (env);
		tmp = tmp->next;
	}
	return (NULL);
}
