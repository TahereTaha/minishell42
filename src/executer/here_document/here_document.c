/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:51:49 by gasroman          #+#    #+#             */
/*   Updated: 2025/01/05 17:35:09 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <readline/readline.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

static int	read_heredeoc(char *delimiter, int *heredoc_pipe)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line || !ft_strncmp(delimiter, line, -1))
		{
			if (line)
				free(line);
			break ;
		}
		ft_putstr_fd(line, heredoc_pipe[1]);
		ft_putstr_fd("\n", heredoc_pipe[1]);
		free(line);
	}
	close(heredoc_pipe[0]);
	close(heredoc_pipe[1]);
	exit(EXIT_SUCCESS);
}

static int	open_heredoc(char *delimiter)
{
	pid_t	heredoc;
	int		heredoc_pipe[2];
	int		status;

	if (pipe(heredoc_pipe) == -1)
		return (errno);
	heredoc = fork();
	if (heredoc == -1)
		return (errno);
	if (heredoc == 0)
	{
		if (heredoc_pipe[0] > 0)
			close(heredoc_pipe[0]);
		read_heredoc(delimiter, heredoc_pipe);
	}
	if (waitpid(heredoc, &status, 0) == -1)
		return (close(heredoc_pipe[0]), errno);
	return (EXIT_SUCCESS);
}

int	run_here_doc(t_list *redir)
{
	t_list	*node;
	t_redir	*content;
	char	*delimiter;

	node = redir;
	while (node)
	{
		content = node->content;
		if (content->kind == HERE_DOCUMENT)
		{
			content = node->next->content;
			delimiter = content->str;
			open_heredoc(delimiter);
		}
		node = node->next;
	}
	return (EXIT_SUCCESS);
}
