/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:30:01 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/21 20:57:27 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdlib.h>
#include <errno.h>

#include "libft.h"
#include "minishell.h"

static size_t	get_section_len(char *str)
{
	size_t	len;

	if (str[0] == '\'' || str[0] == '"')
		len = get_quote_len(str);
	else if (str[0] == '$')
		len = get_env_len(str);
	else
		len = get_char_len(str);
	return (len);
}

static char	*get_section(char *str)
{
	char	*section;

	if (str[0] == '\'' || str[0] == '"')
		section = get_quote_str(str);
	else if (str[i] == '$')
		section = get_env_str(str);
	else
		section = get_char_str(str);
	if (!section)
		return (NULL);
	return (section);
}

static char	*combune(char *str1, char *str2)
{
	char	*str3;

	str3 = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (str3);
}

int	expand_word(char **str_ref)
{
	size_t	i;
	char	*str;
	char	*section;

	i = 0;
	str = ft_strdup(*str_ref);
	if (!str)
		return (ENOMEM);
	while ((*str_ref)[i])
	{
		section = get_section(&(*str_ref)[i]);
		if (!section)
			return (free(str), ENOMEM);
		str = combine(str, section);
		if (!str)
			return (ENOMEM);
		i += get_secton_len(&(*str_ref)[i]);
	}
	free(*str_ref);
	*str_ref = str;
	return (0);
}
