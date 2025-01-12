/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_key_pair.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:27:44 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/12 17:52:09 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"
#include "enviroment.h"
#include "libft.h"
#include "ft_list.h"

t_list	*get_key_node(t_env_ctx *ctx, char *key)
{
	t_list	*node;
	char	*node_key;

	node = ctx->key_value;
	while (node)
	{
		node_key = ((t_key_value *) node->content)->key;
		if (ft_strncmp(node_key, key, -1) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

t_key_value	*get_key_pair(t_env_ctx *ctx, char *key)
{
	t_list		*node;

	node = get_key_node(ctx, key);
	if (!node)
		return (NULL);
	return (node->content);
}
