/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sintax_error_1st.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:22:00 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/12 17:13:42 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_unvalanced_quotes(char *str)
{
	int	i;
	int	in_quotes;

	i = 0;
	in_quotes = 0;
	while (str[i])
	{
		if (str[i] == '\'' && in_quotes == 0)
			in_quotes = 1;
		else if (str[i] == '\'' && in_quotes == 1)
			in_quotes = 0;
		else if (str[i] == '"' && in_quotes == 0)
			in_quotes = 2;
		else if (str[i] == '"' && in_quotes == 2)
			in_quotes = 0;
		i++;
	}
	if (in_quotes)
		return (SYNTAX_ERROR);
	return (0);
}

int	check_sintax_error_1st(char *str)
{
	return (check_unvalanced_quotes(str));
}
