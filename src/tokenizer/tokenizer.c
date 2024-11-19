/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:09:06 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/19 20:39:19 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"
#include "minishell.h"

#include <stdio.h>

int	tokenize(t_list **token_list_ref, char *cmd)
{
	int		err;
	t_list	*token;

	token = NULL;
	*token_list_ref = token;
	err = check_sintax_error_1st(cmd);
	if (err)
	{
		printf("sintax_error\n");
		return (err);
	}
	return (0);
}
