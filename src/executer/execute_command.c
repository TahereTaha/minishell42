/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 07:03:03 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/12 17:38:37 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

static int	execve_command(char **argv, t_env_ctx *env)
{
	char	**envp;
	char	*pathname;
	int		err;

	err = 0;
	envp = env_get_env(env);
	if (!envp)
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

int	execute_command(t_cmd *cmd, t_env_ctx *env)
{
	char	**argv;
	int		err;

	err = 0;
	err = handle_redirection(cmd->redir);
	if (err)
		manage_error(err);
	argv = cmd->argv;
	cmd->argv = NULL;
	free_cmd(cmd);
	err = execve_command(argv, env);
	if (err)
		manage_error(err);
	exit(0);
}
