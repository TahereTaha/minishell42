/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 10:51:56 by gasroman          #+#    #+#             */
/*   Updated: 2025/01/12 16:49:40 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include "libft.h"

int	g_signal_num = 0;

void	persist_signal_num(int signal_num)
{
	g_signal_num = signal_num;
}

void	handle_interactive(int signal_num)
{
	persist_signal_num(signal_num);
	if (signal_num == SIGINT)
	{
//		rl_replace_line("", 0);
//		rl_redisplay();
		rl_done = 1;
	}
}

void	handle_non_interactive(int signal_num)
{
	persist_signal_num(signal_num);
	printf("\n");
}

