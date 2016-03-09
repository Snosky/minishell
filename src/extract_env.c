/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 15:47:33 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/09 17:28:33 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_list	*extract_env(char **envp)
{
	t_list	*lst;
	t_env	env;
	char	*chr;

	lst = NULL;
	while (envp && *envp)
	{
		chr = ft_strchr(*envp, '=');
		env.key = ft_strsub(*envp, 0, chr - *envp);
		env.value = ft_strdup(chr + 1);
		ft_lstpush(&lst, ft_lstnew(&env, sizeof(t_env)));
		envp++;
	}
	return (lst);
}
