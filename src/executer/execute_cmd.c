/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:12:56 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/25 19:52:57 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

int		execute_cmd(t_list *token)
{
	t_list	*cmd;

	cmd = make_cmd_list(token);
	if (!cmd)
		return (ENOMEM);
	print_cmd_list(cmd);
	ft_lstclear(&cmd, (t_del) free_cmd);
	return (0);
}

