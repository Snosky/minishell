/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:37:26 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/03 12:40:59 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_cd(char **args)
{
	if (args[1] == NULL)
		ft_putstr_fd("minishell: expected argument to \"cd\"\n", 2);
	else
		if (chdir(args[1] != 0))
			return (0);
	return (1);
			
}
