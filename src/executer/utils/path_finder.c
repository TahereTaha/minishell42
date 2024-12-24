/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:06:29 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/24 11:04:02 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

#include "libft.h"
#include "minishell.h"

static char	**get_paths(int *err_ref, t_env_ctx *env)
{
	char	**paths;
	char	*path_value;

	*err_ref = env_read(env, &path_value, "PATH");
	if (*err_ref == NO_ENV_KEY || *err_ref == NO_ENV_VAL)
		*err_ref = NO_FILE_OR_DIR;
	if (*err_ref)
		return (NULL);
	paths = ft_split(path_value, ':');
	free(path_value);
	if (!paths)
		*err_ref = ENOMEM;
	return (paths);
}

static char	*pathname_executable(int *err_ref, char *path, char *name)
{
	char	*tmp;
	char	*pathname;

	tmp = ft_strjoin(path, "/");
	if (!tmp)
	{
		*err_ref = ENOMEM;
		return (NULL);
	}
	pathname = ft_strjoin(tmp, name);
	free(tmp);
	if (!pathname)
	{
		*err_ref = ENOMEM;
		return (NULL);
	}
	if (access(pathname, X_OK) == 0)
		return (pathname);
	if (access(pathname, F_OK) == 0)
		*err_ref = NO_PERMISION_CMD;
	free(pathname);
	pathname = NULL;
	return (pathname);
}

static char	*search_path(int *err_ref, char *cmd_name, t_env_ctx *env)
{
	char	*pathname;
	char	**paths;
	int		i;

	paths = get_paths(err_ref, env);
	if (*err_ref)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		pathname = pathname_executable(err_ref, paths[i], cmd_name);
		if (*err_ref)
			return (free_strs(paths), free(pathname), NULL);
		if (pathname)
			return (free_strs(paths), pathname);
		i++;
	}
	free_strs(paths);
	*err_ref = NO_FOUND_CMD;
	return (NULL);
}

int			is_pathname(int *err_ref, char *cmd_name)
{
	if (cmd_name[0] == '.' && cmd_name[1] == '\0')
		*err_ref = NO_FILE_NAME_ARG;
	if (*err_ref)
		return (0);
	if (cmd_name[0] == '/')
		return (1);
	return (0);
}

#include <stdio.h>

char		*path_finder(int *err_ref, char *cmd_name, t_env_ctx *env)
{
	char	*pathname;
	int		err;

	err = 0;
	printf("pathname is: %s\n", cmd_name);
	if (!cmd_name)
		*err_ref = NO_CMD;
	if (!cmd_name)
		return (NULL);
	if (is_pathname(&err, cmd_name))
		return (ft_strdup(cmd_name));
	if (err)
	{
		*err_ref = err;
		return (NULL);
	}
	pathname = search_path(&err, cmd_name, env);
	if (!pathname)
		*err_ref = err;
	return (pathname);
}
