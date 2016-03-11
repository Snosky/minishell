/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:37:26 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/11 22:04:30 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
/*
static int	test_path(char *path)
{
	DIR				*dir;
	struct dirent	*dirent;

	if ((dir = opendir(path)) == NULL)
		return (ERR_CD_NO_EXIST);
	dirent = readdir(dir)
	closedir(dir);
}
*/
static int	test_pwd(char *pwd)
{
	DIR		*dir;

	if ((dir = opendir(pwd)) == NULL)
		return (0);
	closedir(dir);
	return (1);
}

int	ft_cd(t_list *envlst, char **args)
{
	char	*path;

	if (args[1] == NULL)
		args[1] = ft_strdup(find_env(envlst, "HOME")->value);
	else if (args[1][0] == '~')
	{
		path = ft_strsub(args[1], 1, ft_strlen(args[1]) - 1);
		path = ft_strjoin(find_env(envlst, "HOME")->value, path);
		args[1] = ft_strdup(path);
	}
	else if (args[1][0] == '-')
		args[1] = ft_strdup(find_env(envlst, "OLDPWD")->value);
	if (test_pwd(args[1]))
	{
		update_env(envlst, "OLDPWD", find_env(envlst, "PWD")->value);
		update_env(envlst, "PWD", args[1]);
	}
	return (1);
			
}
