/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:20:22 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/22 14:15:11 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int ac, char **av, char **envp)
{
	char	*line;
	char	**args;
	int		status;
	t_list	*envlst;
	int		gnl;

	status = 1;
	(void)ac;
	(void)av;
	signal(SIGINT, SIG_IGN);
	envlst = extract_env(envp);
	while (status > 0)
	{
		prompt(envlst);
		gnl = get_next_line(0, &line);
		if (gnl == -1)
			exit(EXIT_FAILURE);
		else if (gnl == 0)
			exit(EXIT_SUCCESS);
		args = ft_strsplit(line, ' ');
		status = sh_execute(&envlst, args);
		free(args);
		free(line);
	}
	if (status == -1)
		exit(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
