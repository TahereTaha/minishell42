/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:05:32 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/12 19:56:17 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

// int	env_read(char **value_ref, char *key)
// {
// 	char *val;

// 	if (key[0] == 't')
// 	{
// 		val = ft_strdup("");
// 		*value_ref = val;
// 		return (NO_ENV_KEY);
// 	}
// 	val = ft_strdup(key);
// 	if (!val)
// 		return (ENOMEM);
// 	*value_ref = val;
// 	return (0);
// }

t_key_value	*get_key_pair(t_env_ctx *ctx, char *key)
{
	t_list		*node;
	t_key_value	*current_pair;

	node = ctx->key_value;
	while (node)
	{
		current_pair = node->content;
		if (ft_strncmp(key, current_pair->key, -1) == 0)
			return (current_pair);
		node = node->next;
	}
	return (NULL);
}

const int	env_read(t_env_ctx *ctx, char **return_ref, char *key)
{
	t_key_value	*pair;
	char		cpy_value;

	pair = get_key_pair(ctx, key);
	if (!pair)
		return (NO_ENV_KEY);
	if (!pair->value)
	{
		*return_ref = NULL;
		return (0);
	}
	cpy_value = ft_strdup(pair->content);
	if (!cpy_value)
		return (ENOMEM);
	*return_ref = cpy_value;
	return (0);
}
