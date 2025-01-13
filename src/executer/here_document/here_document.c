/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:51:49 by gasroman          #+#    #+#             */
/*   Updated: 2025/01/13 12:49:03 by tatahere         ###   ########.fr       */
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

static int	manage_signal(t_env_ctx *env)
{
	exit_status_set(env, 128 + g_signal_num);
	g_signal_num = 0;
	return (HEREDOC_INTERUPT);
}

static int	fill_heredoc(int fd, \
		t_env_ctx *env, char *delimiter, int has_quotes)
{
	int		err;
	char	*input;

	err = 0;
	while (1)
	{
		input = readline(">");
		if (g_signal_num)
			return (manage_signal(env));
		if (!input && errno == ENOMEM)
			return (ENOMEM);
		if (!input)
			return (HEREDOC_EOF);
		if (!ft_strncmp(delimiter, input, -1))
			return (0);
		if (!has_quotes)
			err = expand_env(&input, env);
		if (err)
			return (err);
		ft_putstr_fd(input, fd);
		free(input);
		ft_putstr_fd("\n", fd);
	}
	return (0);
}

int	run_heredoc(t_redir *redir, t_env_ctx *env)
{
	int	heredoc_pipe[2];
	int	expand_env;
	int	err;

	if (pipe(heredoc_pipe))
		return (errno);
	expand_env = 0;
	if (ft_strchr(redir->str, '"') || ft_strchr(redir->str, '\''))
		expand_env = 1;
	err = remove_quotes(&redir->str);
	if (err)
		return (err);
	err = fill_heredoc(heredoc_pipe[1], env, redir->str, expand_env);
	if (err == HEREDOC_EOF)
	{
		ft_putstr_fd("warning the heredoc ended in eof\n", 2);
		err = 0;
	}
	if (err)
		return (err);
	close(heredoc_pipe[1]);
	redir->fd = heredoc_pipe[0];
	return (0);
}

int	run_heredoc_cmd(t_cmd *cmd, t_env_ctx *env)
{
	t_list	*node;
	int		err;

	err = 0;
	node = cmd->redir;
	while (node)
	{
		if (((t_redir *)node->content)->kind == HERE_DOCUMENT)
			err = run_heredoc(node->content, env);
		if (err)
			return (err);
		node = node->next;
	}
	return (0);
}

int	run_heredoc_cmd_list(t_list *cmd, t_env_ctx *env)
{
	t_list	*node;
	int		err;

	node = cmd;
	err = 0;
	while (node)
	{
		err = run_heredoc_cmd(node->content, env);
		if (err)
			return (err);
		node = node->next;
	}
	return (0);
}
