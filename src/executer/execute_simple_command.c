/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 05:40:53 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/24 06:34:59 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

int	execute_simple_command(t_list *cmd, t_env_ctx *env)
{
	t_cmd			*command;
	t_builtin_kind	kind;

	command = cmd->content;
	kind = get_builtin_kind(command->argv[0]);
	if (kind)
		return (execute_simple_builtin(command, env, kind));
	return (0);
}
