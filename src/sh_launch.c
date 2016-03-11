/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:47:38 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/12 00:22:46 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*find_exec_path(char *paths, char *exec)
{
	char	**apth;
	char	*tmp;

	apth = ft_strsplit(paths, ':');
	while (*apth)
	{
		tmp = ft_strjoin(*apth, "/");
		tmp = ft_strjoin(tmp, exec);
		if (access(tmp, F_OK) == 0)
			return (tmp);
		apth++;
	}
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
	pid_t	pid;
	pid_t	wpid;
	char	*exec_path;
	int		status;

	status = 42;
	exec_path = find_exec_path(find_env(envlst, "PATH")->value, args[0]);
	if (exec_path == NULL)
		return (err_launch(args[0]));
	pid = fork();
	if (pid == 0)
	{
		if (execve(exec_path, args++, export_env(envlst)) == -1)
			return (0);
	}
	else if (pid < 0)
		return (0);
	else
	{
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
