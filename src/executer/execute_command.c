/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 07:03:03 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/24 11:07:19 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

static int	wait_child(t_env_ctx *env, pid_t child)
{
	int	exit_status;

	waitpid(child, &exit_status, 0);
	if (WIFEXITED(exit_status))
		exit_status = WEXITSTATUS(exit_status);
	exit_status_set(env, exit_status);
	return (0);
}

static int	execve_command(char **argv, t_env_ctx *env)
{
	char	**envp;
	char	*pathname;
	int		err;

	err = 0;
	envp = env_get_env(env);
	if (!env)
	{
		free_strs(argv);
		return (ENOMEM);
	}
	pathname = path_finder(&err, argv[0], env);
	env_delete_ctx(env);
	if (err)
	{
		free_strs(argv);
		free_strs(envp);
		return (err);
	}
	if (execve(pathname, argv, envp) == -1)
		return (errno);
	return (0);
}

int		execute_command(t_cmd *cmd, t_env_ctx *env, pid_t child)
{
	char	**argv;
	int		err;

	if (child)
		return (wait_child(env, child));
	err = 0;
	argv = cmd->argv;
	cmd->argv = NULL;
	free_cmd(cmd);
	err = execve_command(argv, env);
	if (err)
		manage_error(err);
	return (0);
}
