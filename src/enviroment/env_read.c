/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:05:32 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/28 17:26:43 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "libft.h"
#include "minishell.h"
#include <stdio.h>

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

const char	*env_read(t_env_ctx *ctx, const char *key)
{
	t_key_value_pair	*current;

	if (!ctx || !key)
		return (NULL);
	current = ctx->key_value_pair;
	while (current)
	{
		if (ft_strncmp(current->key, key, ft_strlen(key)) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
