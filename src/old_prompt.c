/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_prompt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:28:47 by gasroman          #+#    #+#             */
/*   Updated: 2024/11/19 19:46:21 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "minishell.h"

int	exec_prompt(t_shell_ctx *shell_ctx)
{
	char	*input;

	while (1)
	{
		input = readline("minishell: ");
		if (!input)
			return (0);
		if (*input)
			add_history(input);
		run_command(input);
	}
	return (0);
}
