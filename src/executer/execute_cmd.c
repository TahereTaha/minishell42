/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:12:56 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/24 06:34:19 by tatahere         ###   ########.fr       */
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

int		execute_cmd(t_list *token, t_env_ctx *env)
{
	t_list	*cmd;
	int		err;

	err = 0;
	cmd = make_cmd_list(token);
	if (!cmd)
		return (ENOMEM);
	print_cmd_list(cmd, env);
//	err = run_here_documents(t_list *cmd);
//	if (err)
//	{
//		ft_lstclear(&cmd, (t_del) free_cmd);
//		return (err);
//	}
	if (ft_lstsize(cmd) == 1)
		err = execute_simple_command(cmd, env);
//	else
//		err = execute_pipe(cmd);
	ft_lstclear(&cmd, (t_del) free_cmd);
	return (err);
}

