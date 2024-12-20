/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plain_text_ext2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:06:44 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/20 14:07:13 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdlib.h>

#include "libft.h"
#include "minishell.h"

size_t	get_plain_text_ext2_len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\'' && str[i] != '"')
		i++;
	return (i);
}

char	*get_plain_text_ext2_str(char *word)
{
	char	*str;
	size_t	len;

	len = get_plain_text_ext2_len(word);
	str = ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, word, len + 1);
	return (str);
}
