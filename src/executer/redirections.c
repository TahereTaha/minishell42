/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 21:08:58 by gasroman          #+#    #+#             */
/*   Updated: 2025/01/12 17:46:28 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <stdio.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

	// int term = 0;
	// if (dup2(term, 0) == -1)
	// 	printf("estoy malito\n");

static int	fd_to_dup(t_redir *content)
{
	int	fd;

	fd = -1;
	if (content->kind == READ_FROM_FILE)
		fd = open(content->str, O_RDONLY);
	else if (content->kind == WRITE_TO_FILE)
		fd = open(content->str, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (content->kind == APPEND_TO_FILE)
		fd = open(content->str, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if (content->kind == HERE_DOCUMENT)
		fd = content->fd;
	return (fd);
}

int	handle_redirection(t_list *redir)
{
	t_list	*node;
	t_redir	*content;
	int		fd;

	node = redir;
	while (node)
	{
		content = (t_redir *)node->content;
		fd = fd_to_dup(content);
		if (fd == -1)
			return (errno);
		if (content->kind == READ_FROM_FILE || content->kind == HERE_DOCUMENT)
			dup2(fd, STDIN_FILENO);
		else
			dup2(fd, STDOUT_FILENO);
		close(fd);
		node = node->next;
	}
	return (0);
}
