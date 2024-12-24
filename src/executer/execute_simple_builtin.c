/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_builtin.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 05:54:48 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/24 06:38:20 by tatahere         ###   ########.fr       */
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

	err = g_builtins[kind - 1](cmd, env);
	return (err);
}
