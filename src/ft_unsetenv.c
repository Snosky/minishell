/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:50:39 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/22 12:47:47 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	delete_env(void *content, size_t size)
{
	(void)size;
	free(((t_env *)content)->key);
	free(((t_env *)content)->value);
}

static t_list	*err_unsetenv(t_list *env)
{
	ft_putendl_fd("minishell: expected argument to \"unsetenv\"", 2);
	ft_putendl_fd("usage: unsetenv <key>", 2);
	return (env);
}

t_list			*ft_unsetenv(t_list *envlst, char **args)
{
	t_list	*lst;
	t_list	*next;

	lst = NULL;
	if (!args[1])
		return (err_unsetenv(envlst));
	while (envlst)
	{
		next = envlst->next;
		if (ft_strcmp(((t_env *)envlst->content)->key, args[1]))
		{
			envlst->next = NULL;
			ft_lstpush(&lst, envlst);
		}
		else
		{
			ft_lstdelone(&envlst, delete_env);
		}
		envlst = next;
	}
	return (lst);
}
