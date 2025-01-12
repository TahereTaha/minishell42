/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_builtin.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 05:54:48 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/12 17:34:41 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

static void	local_manage_error(t_env_ctx *env)
{
	exit_status_set(env, 1);
	perror("minishell");
}

int	execute_simple_builtin(t_cmd *cmd, t_env_ctx *env, int kind)
{
	int	err;
	int	in_out[2];

	save_in_out(in_out);
	err = handle_redirection(cmd->redir);
	if (err)
		local_manage_error(env);
	if (err)
		return (0);
	err = g_builtins[kind - 1](cmd, env);
	if (!err)
		exit_status_set(env, 0);
	reset_in_out(in_out);
	return (err);
}
