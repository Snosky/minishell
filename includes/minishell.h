/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:22:38 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/22 13:24:42 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <libft.h>
# include <get_next_line.h>
# include <stdlib.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>

typedef struct	s_env
{
	char	*key;
	char	*value;
}				t_env;

t_list			*extract_env(char **envp);
t_env			*find_env(t_list *envlist, char *key);
void			add_env(t_list **envlst, char *key, char *value);
int				update_env(t_list *envlst, char *key, char *value);
void			prompt(t_list *envlst);
int				sh_execute(t_list **envlst, char **args);
void			ft_cd(t_list *envlst, char **args);
int				ft_pwd(t_list *envlst);
int				ft_env(t_list *envlst, char **args);
int				ft_setenv(t_list *envlst, char **args);
t_list			*ft_unsetenv(t_list *envlst, char **args);
int				sh_launch(t_list *envlst, char **args);
char			**export_env(t_list *envlst);
char			*ft_cd_replace(t_list *envlst, char **args);
int				test_pwd(char *pwd);
char			*clear_path(char *pwd);
char			*remove_home(t_list *envlst, char *path);

#endif
