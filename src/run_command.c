/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:24:58 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/19 14:54:11 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

int	run_command(char *cmd, t_env_ctx *env)
{
	t_list	*token;
	int		err;

	err = tokenize(&token, cmd, env);
	free(cmd);
	if (err)
	{
		ft_lstclear(&token, (t_del) free_token);
		return (err);
	}
	err = execute_cmd(token);
	ft_lstclear(&token, (t_del) free_token);
	if (err)
		return (err);
	return (0);
}
