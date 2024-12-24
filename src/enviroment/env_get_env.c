/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_get_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:04:13 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/24 10:42:44 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdlib.h>

#include "minishell.h"
#include "enviroment.h"
#include "libft.h"
#include "ft_list.h"

static int	env_len(t_list *key_pair)
{
	size_t		i;
	t_list		*node;
	t_key_value	*pair;

	i = 0;
	node = key_pair;
	while (node)
	{
		pair = node->content;
		if (pair->value)
			i++;
		node = node->next;
	}
	return (i);
}

static char	*get_str(t_key_value *pair)
{
	char	*tmp;
	char	*env_str;

	tmp = ft_strjoin(pair->key, "=");
	if (!tmp)
		return (NULL);
	env_str = ft_strjoin(tmp, pair->value);
	free(tmp);
	if (!env_str)
		return (NULL);
	return (env_str);
}

char	**env_get_env(t_env_ctx *ctx)
{
	char		**envp;
	t_list		*node;
	size_t		i;
	t_key_value	*pair;

	node = ctx->key_value;
	i = env_len(ctx->key_value);
	envp = ft_calloc(sizeof(char *), i + 1);
	i = 0;
	if (!envp)
		return (NULL);
	while (node)
	{
		pair = node->content;
		if (pair->value)
		{
			envp[i] = get_str(pair);
			if (!envp[i])
				return (free_strs(envp), NULL);
			i++;
		}
		node = node->next;
	}
	return (envp);
}

