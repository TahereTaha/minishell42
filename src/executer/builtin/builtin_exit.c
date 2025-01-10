/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:13:44 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/10 17:48:26 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "libft.h"
#include "minishell.h"

//	returns 1 on overflow of a int
int	ps_intoverflow(char *str, int sign)
{
	long	first;
	long	second;
	int		i;

	i = 0;
	first = 0;
	second = 0;
	while (ft_isdigit(str[i]))
	{
		first = (first * 10) + (str[i] - '0');
		if (first < second)
			return (1);
		if ((sign && first > 2147483648) || (!sign && first > 2147483647))
			return (1);
		second = first;
		i++;
	}
	return (0);
}

//	returns a 1 if there is no overflow and there are only numbers and sign
int	ps_isint(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = 1;
	if (ps_intoverflow(&str[i], sign))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

int	builtin_exit(t_cmd *cmd, t_env_ctx *env)
{
	int	exit_num;

	if (!cmd->argv[1])
		exit(0);
	if (!ps_isint(cmd->argv[1]))
	{
		ft_putstr_fd("exit: numeric argument required\n", 2);
		exit(2);
	}
	if (cmd->argv[2])
	{
		exit_status_set(env, 1);
		ft_putstr_fd("exit: to many arguments\n", 2);
		return (0);
	}
	exit_num = ft_atoi(cmd->argv[1]);
	exit((unsigned char)exit_num);
}
