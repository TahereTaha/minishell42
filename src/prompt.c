/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:38:10 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/11 12:35:50 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

#include "libft.h"
#include "minishell.h"

int prompt(t_env_ctx *env)
{
	char	*input;
	int		err;

	signal(SIGINT, _sigint);
	signal(SIGQUIT, SIG_IGN);
	while (42)
	{
		get_status(1, env->exit_status);
		input = readline("pingushell: ");
		if (!input)
			return (0);
		if (*input)
			add_history(input);
		err = run_command(input, env);
		manage_error(err);
	}
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	return (get_status(0, env->exit_status));
}

