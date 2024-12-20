/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:20:32 by gasroman          #+#    #+#             */
/*   Updated: 2024/12/18 21:34:59 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"
#include "enviroment.h"
#include "libft.h"
#include "ft_list.h"

t_list	*get_key_node_prev(t_env_ctx *ctx, char *key)
{
	t_list	*node;
	t_list	*prev_node;
	char	*node_key;

	node = ctx->key_value;
	while (node)
	{
		node_key = ((t_key_value *) node->content)->key;
		if (ft_strncmp(node_key, key, -1) == 0)
			return (prev_node);
		prev_node = node;
		node = node->next;
	}
	return (NULL);
}

void	remove_first_one(t_env_ctx *ctx)
{
	t_list	*next;

	next = ctx->key_value->next;
	del_key_value(ctx->key_value->content);
	free(ctx->key_value);
	ctx->key_value = next;
}

int	env_unset(t_env_ctx *ctx, char *key)
{
	t_list	*node;
	t_list	*next;
	t_list	*prev_node;

	node = get_key_node(ctx, key);
	if (!node)
		return (NO_ENV_KEY);
	if (node == ctx->key_value)
	{
		remove_first_one(ctx);
		return (0);
	}
	prev_node = get_key_node_prev(ctx, key);
	next = node->next;
	del_key_value(node->content);
	free(node);
	prev_node->next = next;
	return (0);
}
