/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:38:10 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/19 20:40:38 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "libft.h"
#include "minishell.h"

//	temporal this is just a mock of the run command
#include <stdlib.h>
int	run_command(char *cmd)
{
	t_list	*token;
	int		err;

	err = tokenize(&token, cmd);
	free(cmd);
	ft_lstclear(&token, (t_del) free_token);
	return (0);
}

int prompt(void)
{
	char	*input;

	while (42)
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
