/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:20:22 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/22 16:12:50 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	loop_do(t_list **envlst)
{
	char	*line;
	int		status;
	int		gnl;
	char	**args;

	status = 1;
	while (status > 0)
	{
		prompt(*envlst);
		gnl = get_next_line(0, &line);
		if (gnl == -1)
			exit(EXIT_FAILURE);
		else if (gnl == 0)
			exit(EXIT_SUCCESS);
		args = ft_strsplit(line, ' ');
		status = sh_execute(envlst, args);
		free(args);
		free(line);
	}
}

static void	signal_handler(int signum)
{
	(void)signum;
	ft_putchar_fd('\n', 0);
}

int			main(int ac, char **av, char **envp)
{
	t_list	*envlst;

	(void)ac;
	(void)av;
	if (signal(SIGINT, signal_handler) == SIG_IGN)
		signal(SIGINT, SIG_IGN);
	envlst = extract_env(envp);
	loop_do(&envlst);
	return (EXIT_SUCCESS);
}
