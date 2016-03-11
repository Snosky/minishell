/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:29:17 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/11 23:53:00 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		sh_execute(t_list *envlst, char **args)
{
	if (args[0] == NULL)
		return (1);
	else if (ft_strcmp(args[0], "exit") == 0)
		return (0);
	else if (ft_strcmp(args[0], "cd") == 0)
		return (ft_cd(envlst, args));
	else if (ft_strcmp(args[0], "pwd") == 0)
		return (ft_pwd(envlst));
	else if (ft_strcmp(args[0], "env") == 0)
		return (ft_env(envlst, args));
	else if (ft_strcmp(args[0], "setenv") == 0)
		return (ft_setenv(envlst, args));
	else if (ft_strcmp(args[0], "unsetenv") == 0)
		return (ft_unsetenv(&envlst, args));
	return (sh_launch(envlst, args));
}
