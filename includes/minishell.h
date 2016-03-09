/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:22:38 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/09 18:05:18 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <libft.h>
# include <get_next_line.h>
# include <stdlib.h>

typedef struct	s_env
{
	char	*key;
	char	*value;
}				t_env;

t_list	*extract_env(char **envp);
t_env	*find_env(t_list *envlist, char *key);
int		sh_execute(t_list *envlst, char **args);
int		ft_cd(char **args);
int		ft_pwd(t_list *envlst);
int		ft_env(t_list *envlst);

#endif
