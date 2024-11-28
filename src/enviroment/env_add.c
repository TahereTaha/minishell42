/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:14:12 by gasroman          #+#    #+#             */
/*   Updated: 2024/11/28 17:26:00 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_add(t_env_ctx *ctx, const char *key, const char *value)
{
	t_key_value_pair	*new_pair;
	t_key_value_pair	*current;

	if (!ctx || !key || !value)
		return (ENV_ERR_NULL_CTX);
	current = ctx->key_value_pair;
	while (current)
	{
		if (ft_strncmp(current->key, key, ft_strlen(key)) == 0)
			return (ENV_ERR_KEY_EXISTS);
		current = current->next;
	}
	new_pair = crate_pair(key, value);
	if (!new_pair)
		return (ENV_ERR_MEM_ALLOC);
	if (!ctx->key_value_pair)
		ctx->key_value_pair = new_pair;
	else
	{
		current = ctx->key_value_pair;
		while (current->next)
			current = current->next;
		current->next = new_pair;
	}
	return (ENV_SUCCESS);
}
