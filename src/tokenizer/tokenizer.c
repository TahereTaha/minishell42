/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:09:06 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/22 14:07:56 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"
#include "minishell.h"

#include <stdio.h>

int	tokenize(t_list **token_list_ref, char *cmd)
{
	int		err;

	err = check_sintax_error_1st(cmd);
	if (err)
		return (err);
	err = lexer(token_list_ref, cmd);
	if (err)
		return (err);
	print_token_list(*token_list_ref);
	err = check_sintax_error_2nd(*token_list_ref);
	if (err)
		return (err);
	printf("====================================================");
	printf("  here the expansion is being preformed  ");
	printf("====================================================\n");
	err = expand_token_list(*token_list_ref);
	if (err)
		return (err);
	print_token_list(*token_list_ref);
	return (0);
}
