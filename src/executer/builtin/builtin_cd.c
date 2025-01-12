/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 20:58:46 by gasroman          #+#    #+#             */
/*   Updated: 2025/01/12 21:35:12 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "libft.h"
#include "minishell.h"

static int	cd_absolute_path(t_cmd *cmd, t_env_ctx *env)
{
	if (chdir(cmd->argv[1]) == -1)
	{
		return (errno);
	}
	if (env_set(env, "PWD", cmd->argv[1]) == 12)
		return (ENOMEM);
	return (0);
}

static int	cd_relative_path(t_cmd *cmd)
{
	char	cwd[1024];
	char	*final_cwd;
	char	*new_cwd;

	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (errno);
	new_cwd = ft_strjoin(cwd, "/");
	if (!new_cwd)
		return (ENOMEM);
	final_cwd = ft_strjoin(new_cwd, cmd->argv[1]);
	free(new_cwd);
	if (!final_cwd)
		return (ENOMEM);
	if (chdir(final_cwd) == -1)
	{
		free(final_cwd);
		return (errno);
	}
	free(final_cwd);
	return (0);
}

int	builtin_cd(t_cmd *cmd, t_env_ctx *env)
{
	char	cwd[1024];
	int		ret;

	if (!cmd->argv[1])
		return (0);
	else if (cmd->argv[1][0] == '/')
		ret = cd_absolute_path(cmd, env);
	else
		ret = cd_relative_path(cmd);
	if (ret != 0)
		return (ret);
	if (getcwd(cwd, sizeof(cwd)) == NULL)
		return (errno);
	if (env_set(env, "PWD", cwd) == 12)
		return (ENOMEM);
	return (0);
}
