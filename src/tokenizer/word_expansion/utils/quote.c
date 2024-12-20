/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:18:52 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/20 14:53:02 by tatahere         ###   ########.fr       */
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

	len = get_quote_len(word);
	str = ft_calloc(sizeof(char), len - 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, word + 1, len - 1);
	return (str);
}
