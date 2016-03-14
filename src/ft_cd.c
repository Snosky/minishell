/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:37:26 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/14 18:26:15 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	test_pwd(char *pwd)
{
	DIR		*dir;

	ft_putstr("\nTest_pwd :");
	ft_putstr(pwd);

	if ((dir = opendir(pwd)) == NULL)
		return (0);
	closedir(dir);
	return (1);
}

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

int	ft_cd(t_list *envlst, char **args)
{
	char	*path;

	if (args[1] == NULL)
		args[1] = ft_strdup(find_env(envlst, "HOME")->value);
	else if (args[2] != NULL)
	{
		if (args[3] != NULL)
		{
			ft_putendl_fd("cd : too many arguments", 2);
			return (1);
		}
		if ((args[1] = ft_strreplace(args[1], args[2], find_env(envlst, "PWD")->value)) == NULL)
		{
			ft_putstr_fd("cd: string not in pwd: ", 2);
			ft_putendl_fd(args[1], 2);
			return (1);
		}
	}
	else if (args[1][0] == '~')
	{
		path = ft_strsub(args[1], 1, ft_strlen(args[1]) - 1);
		path = ft_strjoin(find_env(envlst, "HOME")->value, path);
		args[1] = ft_strdup(path);
	}		
	else if (args[1][0] == '-')
		args[1] = ft_strdup(find_env(envlst, "OLDPWD")->value);
	else if (ft_strcmp(args[1], ".") == 0)
		return (1);
	else if (ft_strcmp(args[1], "..") == 0)
		args[1] = get_parent_dir(envlst);
	else if (args[1][0] != '/')
		args[1] = ft_strjoin(find_env(envlst, "PWD")->value, ft_strjoin("/", args[1]));
	if (test_pwd(args[1]))
	{
		update_env(envlst, "OLDPWD", find_env(envlst, "PWD")->value);
		update_env(envlst, "PWD", args[1]);
		chdir(args[1]);
	}
	return (1);
}
