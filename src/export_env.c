/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpayen <tpayen@studio.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 00:04:07 by tpayen            #+#    #+#             */
/*   Updated: 2016/03/17 15:58:11 by tpayen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**export_env(t_list *envlst)
{
	char	**ret;
	t_list	*tmp;
	int		i;
	t_env	*env;
	char	*stmp;

	if (!(ret = (char **)malloc(sizeof(char *) * ft_lstcount(envlst) + 1)))
		return (NULL);
	tmp = envlst;
	i = 0;
	ret[0] = NULL;
	while (tmp)
	{
		env = (t_env *)tmp->content;
		if (env->key && env->value)
		{
			stmp = ft_strjoin(env->key, "=");
			ret[i] = ft_strdup(ft_strjoin(stmp, env->value));
			i++;
		}
		tmp = tmp->next;
	}
	free(stmp);
	ret[i] = NULL;
	return (ret);
}
