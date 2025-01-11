/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:51:49 by gasroman          #+#    #+#             */
/*   Updated: 2025/01/11 22:03:27 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <signal.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

static int	read_heredoc(char *delimiter, int *pipe, int expand, t_env_ctx *env)
{
	char	*line;

	while (1)
	{
//		signal(SIGINT, handle_siginth);
		line = readline("> ");
		if (!line || !ft_strncmp(delimiter, line, -1))
		{
			double_free(&line, NULL);
			break ;
		}
		if (expand == 0)
		{
			expand_env(&line, env);
			if (!line)
				break ;
		}
		ft_putstr_fd(line, pipe[1]);
		ft_putstr_fd("\n", pipe[1]);
		free(line);
	}
	close_pipe(pipe);
//	signal(SIGINT, SIG_DFL);
	exit(EXIT_SUCCESS);
}

static int	open_heredoc(t_redir *redir, int expand, t_env_ctx *env)
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
		read_heredoc(redir->str, heredoc_pipe, expand, env);
	}
	if (waitpid(heredoc, &status, 0) == -1)
		return (close(heredoc_pipe[0]), errno);
	redir->fd = heredoc_pipe[0];
	return (EXIT_SUCCESS);
}

static int	quote_search(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}

static t_redir	*find_heredoc_redir(t_list *cmd_list)
{
	t_cmd	*cmd;
	t_list	*redir_list;
	t_redir	*redir;

	while (cmd_list)
	{
		cmd = (t_cmd *)cmd_list->content;
		redir_list = cmd->redir;
		while (redir_list)
		{
			redir = (t_redir *)redir_list->content;
			if (redir->kind == HERE_DOCUMENT)
				return (redir);
			redir_list = redir_list->next;
		}
		cmd_list = cmd_list->next;
	}
	return (NULL);
}

int	run_here_doc(t_list *cmd, t_env_ctx *env)
{
	return (0);
	t_list	*node;
	t_redir	*content;
	int		expand;

	node = cmd;
//	signal(SIGINT, break_it);
//	signal(SIGQUIT, SIG_IGN);
	while (node)
	{
		content = find_heredoc_redir(node);
		if (content)
		{
			expand = quote_search(content->str);
			if (open_heredoc(content, expand, env) == -1)
			{
				ft_putstr_fd("Error: failed to open heredoc\n", STDERR_FILENO);
				return (EXIT_FAILURE);
			}
		}
		node = node->next;
	}
	return (EXIT_SUCCESS);
}

// int	heredoc(t_minishell *mini, t_basic *current)
// {
// 	(void)mini;
// 	if (current && current->data.token->type == R_HER)
// 	{
// 		if (dup2(current->data.token->token_content.redir_here[0], 0) == ERROR)
// 			return (error_msg(PERROR, 1, "Dup2"));
// 		close(current->data.token->token_content.redir_here[0]);
// 	}
// 	return (EXIT_SUCCESS);
// }
