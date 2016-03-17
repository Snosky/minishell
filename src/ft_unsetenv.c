/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:50:39 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/17 16:38:15 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	delete_env(void *content, size_t size)
{
	(void)size;
	free(((t_env *)content)->key);
	free(((t_env *)content)->value);
}

static int	err_unsetenv(void)
{
	ft_putendl_fd("minishell: expected argument to \"unsetenv\"", 2);
	ft_putendl_fd("usage: unsetenv <key>", 2);
	return (1);
}

int		ft_unsetenv(t_list **envlst, char **args)
{
	t_list	*tmp;
	t_list	*flst;
	t_env	*env;

	tmp = *envlst;
	env = (t_env *)tmp->content;
	if (!args[1])
		return (err_unsetenv());
	if (ft_strcmp(env->key, args[1]) == 0)
	{
		*envlst = (*envlst)->next;
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
