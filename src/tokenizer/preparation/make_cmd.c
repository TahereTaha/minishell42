/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:41:05 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/20 16:22:24 by tatahere         ###   ########.fr       */
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
	cmd->argv = make_argv(token);
	if (!cmd->argv)
		return (free(cmd), NULL);
	err = make_redir(token, &redir);
	if (err)
		return (free_strs(cmd->argv), free(cmd), NULL);
	cmd->redir = redir;
	return (cmd);
}
