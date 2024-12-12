/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:14:12 by gasroman          #+#    #+#             */
/*   Updated: 2024/12/10 08:58:06 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

#include "libft.h"
#include "ft_list.h"
#include "enviroment.h"
#include "minishell.h"

static t_key_value	*add_new_key(t_env_ctx *ctx, char *key)
{
	t_key_value	*pair;
	t_list		*node;

	pair = make_key_value(key, "");
	if (!pair)
		return (NULL);
	node = ft_lstnew(pair);
	if (!node)
		return (del_key_value(pair), NULL)
	ft_lstadd_back(&ctx->key_value, node);
	return (pair);
}

int	env_set(t_env_ctx *ctx, char *key, char *value)
{
	t_key_value	*pair;
	char		*cpy_value;

	cpy_value = ft_strdup(value);
	if (!cpy_value)
		return (ENOMEM);
	pair = get_key_pair(ctx, key);
	if (!pair)
		pair = add_new_key(ctx, key);
	if (!pair)
		return (free(cpy_value), ENOMEM);
	free(pair->value);
	pair->value = cpy_value;
	return (0);
}
