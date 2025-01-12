/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes_and_expand_list.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:59:53 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/12 17:14:44 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_list.h"
#include "minishell.h"

/*
static void	debug_local(void)
{
	printf("====================================================");
	printf("  here the expansion is being preformed  ");
	printf("====================================================\n");
}
*/
static int	expand_token(t_list *node, t_env_ctx *env)
{
	t_token	*token;
	int		err;

	token = node->content;
	err = remove_quotes_and_expand_env(&(token->str), env);
	if (err)
		return (err);
	return (0);
}

int	remove_quote_and_expand_list(t_list *token, t_env_ctx *env)
{
	t_list	*node;
	int		err;

	err = 0;
	node = token;
	while (node)
	{
		if (is_word(node))
			err = expand_token(node, env);
		if (err)
			return (err);
		if (is_here_document(node))
			node = node->next->next;
		else
			node = node->next;
	}
	return (0);
}
