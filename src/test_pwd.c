/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:28:25 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/22 13:40:24 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		test_pwd(char *pwd)
{
	if (!pwd)
		return (0);
	if (access(".", F_OK) != 0)
		pwd = clear_path(pwd);
	if (access(pwd, F_OK) == 0)
	{
		if (access(pwd, X_OK))
			return (-1);
		return (1);
	}
	return (0);
}
