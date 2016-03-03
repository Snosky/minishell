/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:20:22 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/03 12:28:59 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(void)
{
	char	*line;
	char	**args;
	int		status;

	status = 1;
	while (status)
	{
		ft_putstr("$> ");
		if (get_next_line(0, &line) == -1)
			exit(EXIT_FAILURE);
		args = ft_strsplit(line, ' ');
		status = sh_execute(args);
		free(args);
		free(line);
	}
	return (EXIT_SUCCESS);
}
