/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:09:06 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/20 14:47:08 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"
#include "minishell.h"

#include <stdio.h>

int	tokenize(t_list **token_list_ref, char *cmd, t_env_ctx *env)
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
	err = remove_quote_and_expand_list(*token_list_ref, env);
	if (err)
		return (err);
	print_token_list(*token_list_ref);
	return (0);
}
