/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:37:26 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/18 18:44:43 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void ft_cd_do(t_list *envlst, char *path)
{
	char	*buf;
	int		len;

	buf = NULL;
	if (test_pwd(path))
	{
		chdir(path);
		len = ft_strlen(path);
		buf = getcwd(buf, len);
		if (!buf)
			buf = clear_path(path);
		if (find_env(envlst, "PWD"))
			update_env(envlst, "OLDPWD", find_env(envlst, "PWD")->value);
		update_env(envlst, "PWD", buf);
	}
	else
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putendl_fd(path, 2);
	}
}

int	ft_cd(t_list *elst, char **ags)
{
	char	*path;
	t_env	*e;

	path = NULL;
	e = NULL;
	if (!ags[1] && (e = find_env(elst, "HOME")))
		path = ft_strdup(e->value);
	else if (ags[2] != NULL && !(path = ft_cd_replace(elst, ags)))
		return (1);
	else if (ags[1][0] == '~' && !ags[2] && (e = find_env(elst, "HOME")))
		path = ft_strreplace("~", e->value, ags[1]);
	else if (ags[1][0] == '-' && !ags[2] && (e = find_env(elst, "OLDPWD")))
		path = ft_strdup(e->value);
	else if (ags[1][0] != '/' && !ags[2] && (e = find_env(elst, "PWD")))
		path = ft_strjoin(e->value, ft_strjoin("/", ags[1]));
	else if (ags[1][0] == '/' && !ags[2])
		path = ft_strdup(ags[1]);
	else if (ags[1])
		path = ft_strdup(ags[1]);
	ft_cd_do(elst, path);
	free(path);
	return (1);
}
