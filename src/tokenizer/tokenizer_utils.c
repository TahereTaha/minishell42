/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 21:02:57 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/21 21:12:16 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "minishell.h"

int	is_pipe(t_list *node)
{
	t_token	*token;

	token = node->content;
	if (token->kind == PIPE)
		return (1);
	return (0);
}

int	is_word(t_list *node)
{
	t_token	*token;

	token = node->content;
	if (token->kind == WORD)
		return (1);
	return (0);
}

int	is_redir(t_list *node)
{
	t_token	*token;

	token = node->content;
	if (token->kind == REDIRECTION)
		return (1);
	return (0);
}

int	is_here_document(t_list *node)
{
	t_token	*token;

	token = node->content;
	if (token->kind != REDIRECTION)
		return (0);
	if (token->str[0] != '<' || token->str[1] != '<')
		return (0);
	return (1);
}
