/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_piped_builtin.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:43:27 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/08 18:21:29 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

int		execute_piped_builtin(t_cmd *cmd, t_env_ctx *env, int kind)
{
	int	err;

	err = g_builtins[kind - 1](cmd, env);
	env_delete_ctx(env);
	free_cmd(cmd);
	manage_error(err);
	exit(0);
}
