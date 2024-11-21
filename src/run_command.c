/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:24:58 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/21 16:24:34 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#include "libft.h"
#include "minishell.h"

int	run_command(char *cmd)
{
	t_list	*token;
	int		err;

	err = tokenize(&token, cmd);
	free(cmd);
	if (err)
	{
		ft_lstclear(&token, (t_del) free_token);
		return (err);
	}
	ft_lstclear(&token, (t_del) free_token);
	return (0);
}
