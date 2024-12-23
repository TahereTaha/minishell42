/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:44:22 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/25 20:06:33 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

void	free_redir(t_redir *redir)
{
	if (redir->fd != -1)
		close(redir->fd);
	free(redir->str);
	free(redir);
}

static t_list	*make_one_redir(t_list *token)
{
	t_list	*node;
	t_redir	*redir;

	redir = ft_calloc(sizeof(t_redir), 1);
	if (!redir)
		return (NULL);
	if (ft_strncmp(">", ((t_token *)token->content)->str, -1))
		redir->kind = WRITE_TO_FILE;
	else if (ft_strncmp(">>", ((t_token *)token->content)->str, -1))
		redir->kind = APPEND_TO_FILE;
	else if (ft_strncmp("<", ((t_token *)token->content)->str, -1))
		redir->kind = READ_FROM_FILE;
	else if (ft_strncmp("<<", ((t_token *)token->content)->str, -1))
		redir->kind = HERE_DOCUMENT;
	redir->fd = -1;
	token = token->next;
	redir->str = ft_strdup(((t_token *)token->content)->str);
	if (!redir->str)
		return (free(redir), NULL);
	node = ft_lstnew(redir);
	if (!node)
		return (free_redir(redir), NULL);
	return (node);
}

int	make_redir(t_list *token, t_list **redir_list_ref)
{
	t_list	*current;
	size_t	i;
	t_list	*redir_list;
	t_list	*redir;

	redir_list = NULL;
	i = 0;
	current = token;
	while (current && !is_pipe(current))
	{
		while (current && is_word(current))
			current = current->next;
		if (!current || is_pipe(current))
			break ;
		redir = make_one_redir(current);
		if (!redir)
			return (ft_lstclear(&redir_list, (t_del) free_redir), ENOMEM);
		ft_lstadd_back(&redir_list, redir);
		current = current->next;
	}
	*redir_list_ref = redir_list;
	return (0);
}
