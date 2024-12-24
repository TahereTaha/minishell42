/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:52:17 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/23 18:42:23 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <unistd.h>

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	int	err;
	t_env_ctx	*env_ctx;

	(void)ac;
	(void)av;
	env_ctx = env_create_ctx(env);
	if (!env_ctx)
		manage_error(ENOMEM);
	err = prompt(env_ctx);
	env_delete_ctx(env_ctx);
	if (err)
		return (err);
	return (42);
}
