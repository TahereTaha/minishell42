/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 05:40:53 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/24 08:05:59 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

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
	}
	return (execute_command(command, env, child));
}
