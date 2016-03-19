/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 12:37:26 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/19 17:59:22 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	err_cd_perm(char *s)
{
	ft_putstr_fd("cd: permission denied: ", 2);
	ft_putendl_fd(s, 2);
}

static void	err_cd_no_file(char *s)
{
	ft_putstr_fd("cd: no such file or directory: ", 2);
	ft_putendl_fd(s, 2);
}

static void err_cd_args(void)
{
	ft_putendl_fd("usage: cd directory ...", 2);
}

static void	ft_cd_do(t_list *envlst, char *path, int show)
{
	char	*buf;
	int		len;
	int		t;

	buf = NULL;
	t = test_pwd(path);
	if (t == 1)
	{
		chdir(path);
		len = ft_strlen(path);
		buf = getcwd(buf, len);
		if (!buf)
			buf = clear_path(path);
		if (find_env(envlst, "PWD"))
			update_env(envlst, "OLDPWD", find_env(envlst, "PWD")->value);
		update_env(envlst, "PWD", buf);
		if (show)
			ft_putendl(remove_home(envlst, buf));
	}
	else if (t == -1)
		err_cd_perm(remove_home(envlst, path));
	else
		err_cd_no_file(remove_home(envlst ,path));
}

void		ft_cd(t_list *lst, char **av)
{
	char	*path;
	t_env	*e;
	int		show;

	path = NULL;
	show = 0;
	if (!av[1] && (e = find_env(lst, "HOME")))
		path = ft_strdup(e->value);
	else if (!av[1])
		return (err_cd_args());
	else if (av[2] != NULL && !(path = ft_cd_replace(lst, av)))
		return ;
	else if (!av[2] && !ft_strcmp(av[1], "~") && (e = find_env(lst, "HOME")))
		path = ft_strreplace("~", e->value, av[1]);
	else if (!av[2] && !ft_strcmp(av[1], "-") && (e = find_env(lst, "OLDPWD")))
	{
		path = ft_strdup(e->value);
		show = 1;
	}
	else if (av[1][0] != '/' && !av[2] && (e = find_env(lst, "PWD")))
		path = ft_strjoin(e->value, ft_strjoin("/", av[1]));
	else if ((av[1][0] == '/' && !av[2]) || (av[1] && !av[2]))
		path = ft_strdup(av[1]);
	ft_cd_do(lst, path, show);
	free(path);
}
