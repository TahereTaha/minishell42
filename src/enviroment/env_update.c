/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:19:02 by gasroman          #+#    #+#             */
/*   Updated: 2024/11/28 17:25:34 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_update(t_env_ctx *ctx, const char *key,
	const char *new_key, const char *new_value)
{
	t_key_value_pair	*current;

	if (!ctx || !key)
		return (ENV_ERR_NULL_CTX);
	current = ctx->key_value_pair;
	while (current)
	{
		if (ft_strncmp(current->key, key, ft_strlen(key)) == 0)
		{
			if (new_key)
			{
				if (env_update_pair(&current->key, new_key) != ENV_SUCCESS)
					return (ENV_ERR_MEM_ALLOC);
			}
			if (new_value)
			{
				if (env_update_pair(&current->value, new_value) != ENV_SUCCESS)
					return (ENV_ERR_MEM_ALLOC);
			}
			return (ENV_SUCCESS);
		}
		current = current->next;
	}
	return (ENV_ERR_KEY_NOT_FOUND);
}
