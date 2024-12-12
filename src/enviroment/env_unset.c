/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:20:32 by gasroman          #+#    #+#             */
/*   Updated: 2024/12/10 11:32:44 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnishell.h"

static void	find_and_redirect_node(t_env_ctx *ctx, char *key)
{
	t_list		*node;
	t_list		*previous;
	t_key_value	*pair;


	node = ctx->key_value->next;
	while (node)
	{
	}

}

static void	redirect_node_before_removal(t_env_ctx *ctx, char *key)
{
	t_key_value	*pair;

	pair = ctx->key_value->content;
	if (ft_strncmp(key, pair->key, -1) == 0)
		ctx->key_value = ctx->key_value->next;
	else
		find_and_redirect_node(ctx, key);
}

int	env_unset(t_env_ctx *ctx, char *key)
{
	
}
