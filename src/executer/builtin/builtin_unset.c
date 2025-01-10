/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:51:33 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/10 17:03:57 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "minishell.h"

int	builtin_unset(t_cmd *cmd, t_env_ctx *env)
{
	int	i;

	i = 1;
	while(cmd->argv[i])
	{
		env_unset(env, cmd->argv[i]);
		i++;
	}
	return (0);
}
