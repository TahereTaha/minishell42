/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:20:32 by gasroman          #+#    #+#             */
/*   Updated: 2024/11/28 17:26:20 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnishell.h"

int	env_delete(t_env_ctx *ctx, const char *key)
{
	t_key_value_pair	*current;
	t_key_value_pair	*previous;

	if (!ctx || !key)
		return (ENV_ERR_NULL_CTX);
	current = ctx->key_value_pair;
	previous = NULL;
	while (current)
	{
		if (ft_strncmp(current->key, key, ft_strlen(key)) == 0)
		{
			if (previous)
				previous->next = current->next;
			else
				ctx->key_value_pair = current->next;
			free(current->key);
			free(current->value);
			free(current);
			return (ENV_SUCCESS);
		}
		previous = current;
		current = current->next;
	}
	return (ENV_ERR_KEY_NOT_FOUND);
}
