/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 05:40:53 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/31 17:44:42 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

static void	wait_child(t_env_ctx *env, pid_t child)
{
	int	exit_status;

	waitpid(child, &exit_status, 0);
	if (WIFEXITED(exit_status))
		exit_status = WEXITSTATUS(exit_status);
	exit_status_set(env, exit_status);
}

int	execute_simple_command(t_list *cmd, t_env_ctx *env)
{
	t_cmd			*command;
	t_builtin_kind	kind;
	pid_t			child;

	command = cmd->content;
	kind = get_builtin_kind(command->argv[0]);
	if (kind)
		return (execute_simple_builtin(command, env, kind));
	child = fork();
	if (child < 0)
		return (errno);
	if (child == 0)
	{
		ft_lstclear(&(cmd->next), (t_del) free_cmd);
		free(cmd);
		execute_command(command, env);
	}
	else
		wait_child(env, child);
	return (0);
}
