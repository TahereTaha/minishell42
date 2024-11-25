/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:41:05 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/25 20:34:33 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

void	free_cmd(t_cmd *cmd)
{
	free_strs(cmd->argv);
	ft_lstclear(&cmd->redir, (t_del) free_redir);
	if (cmd->pipe_front != -1)
		close(cmd->pipe_front);
	if (cmd->pipe_back != -1)
		close(cmd->pipe_back);
	free(cmd);
}

t_cmd	*make_cmd(t_list *token)
{
	t_cmd	*cmd;
	int		err;
	t_list	*redir;

	cmd = ft_calloc(sizeof(t_cmd), 1);
	if (!cmd)
		return (NULL);
	cmd->pipe_front = -1;
	cmd->pipe_back = -1;
	cmd->argv = make_argv(token);
	if (!cmd->argv)
		return (free(cmd), NULL);
	err = make_redir(token, &redir);
	if (err)
		return (free_strs(cmd->argv), free(cmd), NULL);
	cmd->redir = redir;
	return (cmd);
}
