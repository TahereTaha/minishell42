/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:38:10 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/24 11:08:18 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "libft.h"
#include "minishell.h"

int prompt(t_env_ctx *env)
{
	char	*input;
	int		err;

	while (42)
	{
		input = readline("prompt: ");
		if (!input)
			return (0);
		if (*input)
			add_history(input);
		err = run_command(input, env);
		manage_error(err);
	}
	return (0);
}

