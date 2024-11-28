/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delete_ctx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:25:20 by gasroman          #+#    #+#             */
/*   Updated: 2024/11/27 15:25:37 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_delete_ctx(t_env_ctx *ctx)
{
	t_key_value_pair	*current;
	t_key_value_pair	*next;

	if (!ctx)
		return (ENV_ERR_NULL_CTX);
	current = ctx->key_value_pair;
	while (current)
	{
		next = current->next;
		free(current->key);
		free(current->value);
		free(current);
		current = next;
	}
	free(ctx);
	return (ENV_SUCCESS);
}
