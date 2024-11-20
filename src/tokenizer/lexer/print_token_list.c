/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 07:48:40 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/20 10:09:42 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "ft_list.h"
#include "minishell.h"

static void	print_token(t_token *token)
{
	printf("=========================================== this is a token\n");
	if (token->kind == WORD)
		printf("this token is a word.\n");
	else if (token->kind == REDIRECTION)
		printf("this token is a redirection.\n");
	else
		printf("this token is a redirection.\n");
	printf("the token content are: %s\n", token->str);
}

void	print_token_list(t_list *token)
{
	t_list	*current_node;

	current_node = token;
	while (current_node)
	{
		print_token(current_node->content);
		current_node = current_node->next;
	}
}
