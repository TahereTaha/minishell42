/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:06:15 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/10 17:10:21 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>

#include "libft.h"
#include "minishell.h"

int	builtin_env(t_cmd *cmd, t_env_ctx *env)
{
	char	**envp;
	int		i;

	(void)cmd;
	envp = env_get_env(env);
	if (!envp)
		return (ENOMEM);
	i = 0;
	while (envp[i])
	{
		ft_putstr_fd(envp[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	free_strs(envp);
	return (0);
}
