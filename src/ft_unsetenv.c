/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:50:39 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/11 17:10:16 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	delete_env(void *content, size_t size)
{
	(void)size;
	free(((t_env *)content)->key);
	free(((t_env *)content)->value);
}

int		ft_unsetenv(t_list **envlst, char **args)
{
	t_list	*tmp;
	t_list	*flst;
	t_env	*env;

	tmp = *envlst;
	env = (t_env *)tmp->content;
	if (ft_strcmp(env->key, args[1]) == 0)
	{
		*envlst = tmp->next;
		ft_lstdelone(&tmp, delete_env);
	}
	else
	{
		while (tmp->next)
		{
			env = (t_env *)tmp->next->content;
			if (ft_strcmp(env->key, args[1]) == 0)
			{
				flst = tmp->next;
				tmp->next = tmp->next->next;
				ft_lstdelone(&flst, delete_env);
				break ;
			}
			tmp = tmp->next;
		}
	}
	return (1);
}
