/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:08:41 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/09 21:23:19 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdlib.h>

#include "minishell.h"
#include "enviroment.h"
#include "libft.h"
#include "ft_list.h"

static char	*get_str(t_key_value *pair)
{
	char	*tmp;
	char	*env_str;

	if (!pair->value)
		return (ft_strdup(pair->key));
	tmp = ft_strjoin(pair->key, "=");
	if (!tmp)
		return (NULL);
	env_str = ft_strjoin(tmp, pair->value);
	free(tmp);
	if (!env_str)
		return (NULL);
	return (env_str);
}

char	**env_get_export(t_env_ctx *ctx)
{
	char		**envp;
	t_list		*node;
	size_t		i;
	t_key_value	*pair;

	node = ctx->key_value;
	i = ft_lstsize(ctx->key_value);
	envp = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	if (!envp)
		return (NULL);
	while (node)
	{
		pair = node->content;
		envp[i] = get_str(pair);
		if (!envp[i])
			return (free_strs(envp), NULL);
		i++;
		node = node->next;
	}
	return (envp);
}

