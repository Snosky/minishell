/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:29:17 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/09 18:04:37 by tpayen           ###   ########.fr       */
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
		return (ft_cd(args));
	else if (ft_strcmp(args[0], "pwd") == 0)
		return (ft_pwd(envlst));
	else if (ft_strcmp(args[0], "env") == 0)
		return (ft_env(envlst));
	/*else
		sh_launch(args);*/
	return (1);
}
