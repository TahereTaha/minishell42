/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_word_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 06:38:31 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/20 10:16:27 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

static int	double_quote_len(char *str)
{
	int i;

	i = 0;
	if (str[i] != '"')
		return (0);
	i++;
	while (str[i] != '"')
		i++;
	i++;
	return (i);
}

static int	singel_quote_len(char *str)
{
	int i;

	i = 0;
	if (str[i] != '\'')
		return (0);
	i++;
	while (str[i] != '\'')
		i++;
	i++;
	return (i);
}

static t_list	*make_node(char *cmd, size_t len)
{
	t_list	*node;
	t_token	*token;
	char	*str;
	
	str = ft_substr(cmd, 0, len);
	if (!str)
		return (NULL);
	token = ft_calloc(sizeof(t_token), 1);
	if (!token)
	{
		free(str);
		return (NULL);
	}
	token->kind = WORD;
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

int	make_word_token(t_list **node_ref, char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && !ft_strchr("><| \t", str[i]))
	{
		if (str[i] == '\'')
			i += singel_quote_len(&str[i]);
		else if (str[i] == '"')
			i += double_quote_len(&str[i]);
		else
			i += 1;
	}
	*node_ref = make_node(str, i);
	if (!*node_ref)
		return (ENOMEM);
	return (0);
}
