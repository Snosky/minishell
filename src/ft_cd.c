/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:37:26 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/15 19:22:19 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
/*
static char	*get_parent_dir(t_list *envlst)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(find_env(envlst, "PWD")->value, '/');
	while (tmp[i])
	{
		if (tmp[i + 1] == NULL)
		{
			free(tmp[i]);
			tmp[i] = NULL;
			break ;
		}
		i++;
	}
	return (ft_strjoin("/", ft_strimp(tmp, "/")));
}
*/
static void ft_cd_do(t_list *envlst, char *path)
{
	if (test_pwd(path))
	{
		path = clear_path(path);
		update_env(envlst, "OLDPWD", find_env(envlst, "PWD")->value);
		update_env(envlst, "PWD", path);
		chdir(path);
	}
	else
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(path, 2);
	}
}

int	ft_cd(t_list *envlst, char **args)
{
	char	*path;

	path = NULL;
	if (args[1] == NULL)
		path = ft_strdup(find_env(envlst, "HOME")->value);
	else if (args[2] != NULL && (path = ft_cd_replace(envlst, args)) == NULL)
		return (1);
	else if (args[1][0] == '~' && args[2] == NULL)
		path = ft_strreplace("~", find_env(envlst, "HOME")->value, args[1]);
	else if (args[1][0] == '-' && args[2] == NULL)
		path = ft_strdup(find_env(envlst, "OLDPWD")->value);
	/*else if (ft_strcmp(args[1], ".") == 0 && args[2] == NULL)
		return (1);
	else if (ft_strcmp(args[1], "..") == 0 && args[2] == NULL)
		path = get_parent_dir(envlst);*/
	else if (args[1][0] != '/' && args[2] == NULL)
		path = ft_strjoin(find_env(envlst, "PWD")->value, ft_strjoin("/", args[1]));
	else if (args[1][0] == '/' && args[2] == NULL)
		path = ft_strdup(args[1]);
	ft_cd_do(envlst, path);
	free(path);
	return (1);
}
