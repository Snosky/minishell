/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:47:38 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/19 17:37:48 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*find_exec_path(t_env *path, char *exec)
{
	char	**apth;
	char	*tmp;

	if (path)
	{
		apth = ft_strsplit(path->value, ':');
		while (*apth)
		{
			tmp = ft_strjoin(*apth, "/");
			tmp = ft_strjoin(tmp, exec);
			if (access(tmp, F_OK) == 0)
				return (tmp);
			apth++;
		}
	}
	if (access(exec, F_OK) == 0)
		return (exec);
	return (NULL);
}

static int	err_launch(char *exec)
{
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putendl_fd(exec, 2);
	return (1);
}

int			sh_launch(t_list *envlst, char **args)
{
	pid_t	father;
	char	*exec_path;

	exec_path = find_exec_path(find_env(envlst, "PATH"), args[0]);
	if (exec_path == NULL)
	{
		err_launch(args[0]);
		return (1);
	}
	father = fork();
	if (father > 0)
		waitpid(father, NULL, 0);
	if (!father)
	{
		signal(SIGINT, SIG_DFL);
		if (execve(exec_path, args++, export_env(envlst)) < 0)
		{
			ft_putstr_fd("minishell: exec format error: ", 2);
			ft_putendl_fd(exec_path, 2);
			exit(2);
		}
	}
	return (1);
}
