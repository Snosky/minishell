/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 00:04:07 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/12 00:11:48 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**export_env(t_list *envlst)
{
	char	**ret;
	t_list	*tmp;
	int		i;
	t_env	*env;

	if (!(ret = (char **)malloc(sizeof(char *) * ft_lstcount(envlst) + 1)))
		return (NULL);
	tmp = envlst;
	i = 0;
	while (tmp)
	{
		env = (t_env *)tmp->content;
		ret[i] = ft_strdup(ft_strjoin(ft_strjoin(env->key, "="), env->value));
		i++;
		tmp = tmp->next;
	}
	return (ret);
}
