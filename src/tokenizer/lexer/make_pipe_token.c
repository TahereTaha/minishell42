/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pipe_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:15:53 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/12 17:16:46 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

static t_list	*make_node(void)
{
	char	*str;
	t_token	*token;
	t_list	*node;

	str = ft_strdup("|");
	if (!str)
		return (NULL);
	token = ft_calloc(sizeof(t_token), 1);
	if (!token)
	{
		free(str);
		return (NULL);
	}
	token->kind = PIPE;
	token->str = str;
	node = ft_lstnew(token);
	if (!node)
	{
		free(str);
		free(token);
		return (NULL);
	}
	return (node);
}

int	make_pipe_token(t_list **node_ref)
{
	*node_ref = make_node();
	if (!*node_ref)
		return (ENOMEM);
	return (0);
}
