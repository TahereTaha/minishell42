/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:12:56 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/11 11:00:51 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"
/*
static int	execute_simple_command(t_cmd *cmd, t_env_ctx *env)
{
	t_bultin_kind	builtin_kind;

	builtin_kind = get_builtin_kind(cmd->argv[0]);
	if (builtin_kind)
		return ();
}
*/

int	execute_cmd(t_list *token, t_env_ctx *env)
{
	t_list	*cmd;
	int		err;

	err = 0;
	cmd = make_cmd_list(token);
	if (!cmd)
		return (ENOMEM);
//	print_cmd_list(cmd, env);
	err = run_here_doc(cmd, env);
	if (err)
	{
		ft_lstclear(&cmd, (t_del) free_cmd);
		return (err);
	}
	if (ft_lstsize(cmd) == 1)
		err = execute_simple_command(cmd, env);
	else
	{
		err = execute_pipe(cmd, env);
	}
	ft_lstclear(&cmd, (t_del) free_cmd);
	return (err);
}

