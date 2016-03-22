/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:47:33 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/22 12:38:50 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*extract_env(char **envp)
{
	t_list	*lst;
	t_env	env;
	char	**tab;
	int		i;

	lst = NULL;
	i = 0;
	while (envp[i])
	{
		tab = ft_strsplit(envp[i], '=');
		if (tab[0] && tab[1])
		{
			env.key = ft_strdup(tab[0]);
			env.value = ft_strdup(tab[1]);
			ft_lstpush(&lst, ft_lstnew(&env, sizeof(t_env)));
		}
		i++;
	}
	return (lst);
}
