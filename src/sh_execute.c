/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:29:17 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/03 13:16:10 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		sh_execute(char **args)
{
	if (args[0] == NULL)
		return (1);
	else if (ft_strcmp(args[0], "exit") == 0)
		return (0);
	else if (ft_strcmp(args[0], "cd") == 0)
		return (ft_cd(args));
	return (1);
}
