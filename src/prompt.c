/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:38:10 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/13 13:20:19 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>

#include "libft.h"
#include "minishell.h"

static int	event(void)
{
	return (0);
}

int	prompt(t_env_ctx *env)
{
	char	*input;
	int		err;

	rl_event_hook = event;
	signal(SIGINT, handle_interactive);
	signal(SIGQUIT, SIG_IGN);
	while (42)
	{
		input = readline("pingushell: ");
		if (g_signal_num)
		{
			exit_status_set(env, 128 + g_signal_num);
			g_signal_num = 0;
			continue ;
		}
		if (!input)
			return (0);
		if (*input)
			add_history(input);
		err = run_command(input, env);
		manage_error(err);
	}
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	return (0);
}
