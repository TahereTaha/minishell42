/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:33:10 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/24 06:51:13 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static int	check_flag(char *flag)
{
	int	i;

	if (flag[0] != '-')
		return (0);
	i = 1;
	while (flag[i] == 'n')
		i++;
	if (flag[i] == '\0')
		return (1);
	return (0);
}

static int	get_index_first_no_flag(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!check_flag(argv[i]))
			return (i);
		i++;
	}
	return (i);
}

int	builtin_echo(t_cmd *cmd)
{
	int	i;

	i = get_index_first_no_flag(cmd->argv);
	while (cmd->argv[i])
	{
		ft_putstr_fd(cmd->argv[i], 0);
		if (cmd->argv[i + 1])
			ft_putstr_fd(" ", 0);
		i++;
	}
	if (!check_flag(cmd->argv[1]))
		ft_putstr_fd("\n", 0);
	return (0);
}
