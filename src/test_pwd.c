/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:28:25 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/15 16:29:06 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int		test_pwd(char *pwd)
{
	DIR *dir;

	if ((dir = opendir(pwd)) == NULL)
		return (0);
	closedir(dir);
	return (1);
}