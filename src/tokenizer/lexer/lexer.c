/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 06:01:29 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/20 10:13:50 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

static int	make_token(t_list **node_ref, char *str)
{
	int	err;

	if (ft_strchr("|", *str))
		err = make_pipe_token(node_ref);
	else if (ft_strchr("<>", *str))
		err = make_redirection_token(node_ref, str);
	else
		err = make_word_token(node_ref, str);
	return (err);
}

int	lexer(t_list **token_list_ref, char *str)
{
	size_t	i;
	int		err;
	t_list	*current_node;

	i = 0;
	*token_list_ref = NULL;
	while (str[i])
	{
		while (ft_strchr(" \t\n", str[i]))
			i++;
		err = make_token(&current_node, &str[i]);
		if (err)
			break ;
		ft_lstadd_back(token_list_ref, current_node);
		i += ft_strlen(((t_token *)current_node->content)->str);
	}
	if (err)
	{
		ft_lstclear(token_list_ref, (t_del) free_token);
		return (err);
	}
//	print_token_list(*token_list_ref);
	return (0);
}
