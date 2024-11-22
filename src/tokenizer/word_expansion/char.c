/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:31:10 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/22 13:48:16 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdlib.h>

#include "libft.h"
#include "minishell.h"

size_t	get_char_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '$' && str[i] != '\'' && str[i] != '"')
		i++;
	return (i);
}

char	*get_char_str(char *word)
{
	char	*str;
	size_t	len;

	len = get_char_len(word);
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, word, len + 1);
	return (str);
}