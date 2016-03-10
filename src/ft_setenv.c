/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 16:35:27 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/10 16:49:46 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	err_setenv(void)
{
	ft_putendl_fd("minishell: expected argument to \"setenv\"", 2);
	ft_putendl_fd("ex: setenv <key> <value>", 2);
	return (1);
}

int			ft_setenv(t_list *envlst, char **args)
{
	t_env	*env;

	if (args[1] == NULL || args[2] == NULL)
		return (err_setenv());
	if ((env = find_env(envlst, args[1])) != NULL)
	{
		free(env->value);
		env->value = ft_strdup(args[2]);
	}
	else
		add_env(&envlst, args[1], args[2]);
	return (1);
}
