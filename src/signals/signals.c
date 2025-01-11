/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:51:56 by gasroman          #+#    #+#             */
/*   Updated: 2025/01/11 17:18:18 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include "libft.h"

void	handle_siginth(int sig)
{
	if (sig == SIGINT)
	{
		printf(">\n");
		exit(130);
	}
}

int	get_break_it(int flag, int value)
{
	static int	_break;

	if (flag == 1)
		_break = value;
	return (_break);
}

void	break_it(int signal)
{
	if (signal == SIGINT)
		get_break_it(1, 1);
}

int	get_status(int flag, int value)
{
	static int	var;

	if (flag == 1)
		var = value;
	// printf("var = %d\n", var);
	return (var);
}

void	_sigint(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		get_status(1, 130);
	}
}

void	handle_signaled(int *status, int signal)
{
	if (signal == 2)
		printf("^C\n");
	else if (signal == 3)
		printf("Quit: (core dumped)\n");
	*status = 128 + signal;
}