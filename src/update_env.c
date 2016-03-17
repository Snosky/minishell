/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 20:55:49 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/17 15:57:39 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	update_env(t_list *envlst, char *key, char *value)
{
	t_env	*env;

	if ((env = find_env(envlst, key)) != NULL)
	{
		free(env->value);
		env->value = ft_strdup(value);
		return (1);
	}
	else
		add_env(&envlst, key, value);
	return (0);
}
