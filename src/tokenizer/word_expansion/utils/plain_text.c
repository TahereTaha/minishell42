/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plain_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:31:10 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/13 13:26:39 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdlib.h>

#include "libft.h"
#include "minishell.h"

static int	is_env(char *str)
{
	if (str[0] != '$')
		return (0);
	if (str[1] == '_' || ft_isalpha(str[1]) || str[1] == '?')
		return (1);
	return (0);
}

size_t	get_plain_text_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && !is_env(&str[i]) && str[i] != '\'' && str[i] != '"')
		i++;
	return (i);
}

char	*get_plain_text_str(char *word)
{
	char	*str;
	size_t	len;

	len = get_plain_text_len(word);
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, word, len + 1);
	return (str);
}
