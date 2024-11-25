/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 19:13:34 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/25 20:09:42 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

static t_list	*get_next_cmd_start(t_list *token)
{
	t_list	*current;

	current = token;
	while (current && !is_pipe(current))
		current = current->next;
	if (current)
		current = current->next;
	return (current);
}

static t_list	*make_node(t_list *token)
{
	t_cmd	*cmd;
	t_list	*node;

	cmd = make_cmd(token);
	if (!cmd)
		return (NULL);
	node = ft_lstnew(cmd);
	if (!node)
		return (free_cmd(cmd), NULL);
	return (node);
}

t_list	*make_cmd_list(t_list *token)
{
	t_list	*cmd;
	t_list	*current_token;
	t_list	*node;

	cmd = NULL;
	current_token = token;
	while (current_token)
	{
		node = make_node(current_token);
		if (!node)
			return (ft_lstclear(&cmd, (t_del) free_cmd), NULL);
		ft_lstadd_back(&cmd, node);
		current_token = get_next_cmd_start(current_token);
	}
	return (cmd);
}
