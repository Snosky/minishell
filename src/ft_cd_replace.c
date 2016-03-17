/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_replace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 16:25:17 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/17 16:41:43 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_cd_replace(t_list *envlst, char **args)
{
	char	*tmp;
	t_env	*pwd;

	if ((pwd = find_env(envlst, "PWD")) == NULL)
		return (NULL);
	if (args[3] != NULL)
	{
		ft_putendl_fd("cd: too many arguments", 2);
		return (NULL);
	}
	if ((tmp = ft_strreplace(args[1], args[2], pwd->value)) == NULL)
	{
		ft_putstr_fd("cd: string not in pwd: ", 2);
		ft_putendl_fd(args[1], 2);
		return (NULL);
	}
	if (test_pwd(tmp))
		ft_putendl(tmp);
	return (tmp);
}
