/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sintax_error_2nd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:23:20 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/12 19:48:10 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "minishell.h"

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
		if (is_redir(node) && !is_word(node->next))
			return (SYNTAX_ERROR);
		if (is_pipe(node) && !(is_word(node->next) || is_redir(node->next)))
			return (SYNTAX_ERROR);
		node = node->next;
	}
	if (is_pipe(node) || is_redir(node))
		return (SYNTAX_ERROR);
	return (0);
}
