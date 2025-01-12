/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 20:12:17 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/12 17:22:48 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>

#include "libft.h"
#include "minishell.h"

static int	valid_key(char *key)
{
	int	i;

	i = 0;
	while (key[i] && key[i] != '=')
	{
		if (key[i] != '_' && !ft_isalnum(key[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	key_value(t_env_ctx *env, char *key)
{
	char	*value;
	int		err;

	value = NULL;
	err = env_read(env, &value, key);
	if (err)
		return (0);
	free(value);
	if (!value)
		return (0);
	return (1);
}

static int	export_variable(char *str, t_env_ctx *env)
{
	char	*key;
	char	*value;
	int		err;

	if (!valid_key(str))
	{
		ft_putstr_fd("not a valid identifier\n", 2);
		return (NO_VALID_KEY);
	}
	if (!ft_strchr(str, '=') && !key_value(env, str))
		return (env_set(env, str, NULL));
	else if (!ft_strchr(str, '='))
		return (0);
	key = ft_substr(str, 0, ft_strchr(str, '=') - str);
	if (!key)
		return (ENOMEM);
	value = ft_strdup(ft_strchr(str, '=') + 1);
	if (!value)
		return (free(value), ENOMEM);
	err = env_set(env, key, value);
	free(key);
	free(value);
	return (err);
}

int	print_export(t_env_ctx *env)
{
	char	**envp;
	int		i;

	envp = env_get_export(env);
	if (!envp)
		return (ENOMEM);
	i = 0;
	while (envp[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(envp[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
	free_strs(envp);
	return (0);
}

int	builtin_export(t_cmd *cmd, t_env_ctx *env)
{
	int	err;
	int	one_incorect_key;
	int	i;

	if (!cmd->argv[1])
		return (print_export(env));
	i = 1;
	err = 0;
	one_incorect_key = 0;
	while (cmd->argv[i])
	{
		err = export_variable(cmd->argv[i], env);
		if (err && err != NO_VALID_KEY)
			return (err);
		else
			one_incorect_key = 1;
		i++;
	}
	if (err)
		exit_status_set(env, 1);
	return (0);
}
