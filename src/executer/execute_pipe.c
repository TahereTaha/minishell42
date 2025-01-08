/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:51:08 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/08 16:23:58 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

static void	wait_all_child(t_env_ctx *env, pid_t *child, size_t size)
{
	int		exit_status;
	size_t	i;

	i = 0;
	while (i < size)
	{
		waitpid(child[i], &exit_status, 0);
		i++;
	}
	if (WIFEXITED(exit_status))
		exit_status = WEXITSTATUS(exit_status);
	exit_status_set(env, exit_status);
}

//	this will not return.
static void	execute_pipe_segment(t_cmd *command, t_env_ctx *env)
{
	t_builtin_kind	kind;

	kind = get_builtin_kind(command->argv[0]);
//	print_cmd(command, env);
	if (kind)
		execute_piped_builtin(command, env, kind);
	else
		execute_command(command, env);
}

pid_t	fork_child_proses
(t_list *cmd, t_env_ctx *env, size_t index, t_struct_pipe *pipe)
{
	pid_t	child;
	t_cmd	*command;

	child = fork();
	if (child < 0)
	{
		env_delete_ctx(env);
		ft_lstclear(&cmd, (t_del) free_cmd);
		manage_error(errno);
	}
	if (child != 0)
		return (child);
	command = ft_lstpurge(&cmd, (t_del) free_cmd, index);
	hook_to_pipe((int *)&pipe->front, (int *)&pipe->back);
	execute_pipe_segment(command, env);
	return (child);
}

int	execute_pipe(t_list *cmd, t_env_ctx *env)
{
	t_struct_pipe	pipe_s;
	pid_t			*child_list;
	size_t			len;
	size_t			i;

	init_pipe(&pipe_s);
	len = ft_lstsize(cmd);
	child_list = ft_calloc(sizeof(pid_t *), len);
	if (!child_list)
		return (ENOMEM);
	i = 0;
	while ((i + 1) < len)
	{
		if (pipe((int *)&pipe_s.front))
			return (errno);
		child_list[i] = fork_child_proses(cmd, env, i, &pipe_s);
		move_pipe_back(&pipe_s);
		i++;
	}
	child_list[i] = fork_child_proses(cmd, env, i, &pipe_s);
	close_pipe((int *)&pipe_s.back);
	wait_all_child(env, child_list, len);
	free(child_list);
	return (0);
}
