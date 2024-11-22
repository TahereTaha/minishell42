/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:59:53 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/22 14:00:09 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "minishell.h"

static int	expand_token(t_list *node)
{
	t_token	*token;
	int		err;

	token = node->content;
	err = expand_word(&(token->str));
	if (err)
		return (err);
	return (0);
}

int		expand_token_list(t_list *token)
{
	t_list	*node;
	int		err;

	err = 0;
	node = token;
	while (node)
	{
		if (is_word(node))
			err = expand_token(node);
		if (err)
			return (err);
		if (is_here_document(node))
			node = node->next->next;
		else
			node = node->next;
	}
	return (0);
}
