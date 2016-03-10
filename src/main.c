/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:20:22 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/10 18:09:29 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int ac, char **av, char **envp)
{
	char	*line;
	char	**args;
	int		status;
	t_list	*envlst;

	status = 1;
	(void)ac;
	(void)av;
	envlst = extract_env(envp);
	while (status)
	{
		ft_putstr("$> ");
		if (get_next_line(0, &line) == -1)
			exit(EXIT_FAILURE);
		args = ft_strsplit(line, ' ');
		status = sh_execute(envlst, args);
		free(args);
		free(line);
	}
	return (EXIT_SUCCESS);
}
