/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redirection_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:28:16 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/20 10:17:36 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

static t_list	*make_node(char *cmd, size_t len)
{
	char	*str;
	t_token	*token;
	t_list	*node;

	str = ft_substr(cmd, 0, len);
	if (!str)
		return (NULL);
	token = ft_calloc(sizeof(t_token), 1);
	if (!token)
	{
		free(str);
		return (NULL);
	}
	token->kind = REDIRECTION;
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

int	make_redirection_token(t_list **node_ref, char *str)
{
	if (str[0] == '>' && str[1] != '>')
		*node_ref = make_node(str, 1);
	if (str[0] == '<' && str[1] != '<')
		*node_ref = make_node(str, 1);
	if (str[0] == '>' && str[1] == '>')
		*node_ref = make_node(str, 2);
	if (str[0] == '<' && str[1] == '<')
		*node_ref = make_node(str, 2);
	if (!*node_ref)
		return (ENOMEM);
	return (0);
}
