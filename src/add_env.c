/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:40:50 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/10 16:42:37 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	add_env(t_list **envlst, char *key, char *value)
{
	t_env	env;

	env.key = ft_strdup(key);
	env.value = ft_strdup(value);
	ft_lstpush(envlst, ft_lstnew(&env, sizeof(t_env)));
}
