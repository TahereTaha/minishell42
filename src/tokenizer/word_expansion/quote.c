/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:18:52 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/22 15:40:23 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdlib.h>

#include "libft.h"
#include "minishell.h"

size_t	get_quote_len(char *str)
{
	size_t	i;
	char	quotes;

	i = 0;
	quotes = str[0];
	i++;
	while (str[i] && quotes != str[i])
		i++;
	return (i + 1);
}

char	*get_quote_str(char *word)
{
	char	*str;
	size_t	len;
	int		err;

	len = get_quote_len(word);
	str = ft_calloc(sizeof(char), len - 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, word + 1, len - 1);
	if (word[0] == '\'')
		return (str);
	err = expand_quoted_word(&str);
	if (err)
		return (free(str), NULL);
	return (str);
}
