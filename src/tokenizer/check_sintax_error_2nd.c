/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sintax_error_2nd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:23:20 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/21 16:40:16 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "minishell.h"

static int	is_pipe(t_list *node)
{
	t_token	*token;

	token = node->content;
	if (token->kind == PIPE)
		return (1);
	return (0);
}

static int	is_word(t_list *node)
{
	t_token	*token;

	token = node->content;
	if (token->kind == WORD)
		return (1);
	return (0);
}

static int	is_redir(t_list *node)
{
	t_token	*token;

	token = node->content;
	if (token->kind == REDIRECTION)
		return (1);
	return (0);
}

int	check_sintax_error_2nd(t_list *token)
{
	t_list	*node;

	if (!token)
		return (0);
	node = token;
	if (is_pipe(node))
		return (SYNTAX_ERROR);
	while (node->next)
	{
		if ((is_pipe(node) || is_redir(node)) && !is_word(node->next))
			return (SYNTAX_ERROR);
		node = node->next;
	}
	if (is_pipe(node) || is_redir(node))
		return (SYNTAX_ERROR);
	return (0);
}
