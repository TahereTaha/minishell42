/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_builtin.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 05:54:48 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/08 18:39:14 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

int		execute_simple_builtin(t_cmd *cmd, t_env_ctx *env, int kind)
{
	int	err;
	int	in_out[2];

	save_in_out(in_out);
	handle_redirection(cmd->redir);
	err = g_builtins[kind - 1](cmd, env);
	reset_in_out(in_out);
	return (err);
}
