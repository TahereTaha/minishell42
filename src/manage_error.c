/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:41:30 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/12 17:10:22 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "libft.h"
#include "minishell.h"

static void	manage_pathfinder_error(int err)
{
	if (err == NO_CMD)
		exit(0);
	if (err == NO_FOUND_CMD)
	{
		ft_putstr_fd("minishell: command not found\n", 2);
		exit(127);
	}
	if (err == NO_FILE_OR_DIR)
	{
		ft_putstr_fd("minishell: no such file or directory\n", 2);
		exit(127);
	}
	if (err == NO_PERMISION_CMD)
	{
		ft_putstr_fd("minishell: Permision denied\n", 2);
		exit(126);
	}
	if (err == NO_FILE_NAME_ARG)
	{
		ft_putstr_fd("minishell: filename argument required\n", 2);
		exit(2);
	}
}

static void	manage_custom_error(int err)
{
	if (err == SYNTAX_ERROR)
		ft_putstr_fd("syntax error\n", 2);
	if (err >= NO_CMD)
		manage_pathfinder_error(err);
}

static void	manage_system_error(void)
{
	perror("minishell");
	exit(1);
}

void	manage_error(int err)
{
	if (!err)
		return ;
	if (err < SYNTAX_ERROR)
		manage_system_error();
	manage_custom_error(err);
}
