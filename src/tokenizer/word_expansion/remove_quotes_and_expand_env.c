/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes_and_expand_env.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:56:41 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/20 15:32:45 by tatahere         ###   ########.fr       */
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

	if (str[0] == '$')
		len = get_env_len(str);
	else if (str[0] == '"' || str[0] == '\'')
		len = get_quote_len(str);
	else
		len = get_plain_text_len(str);
	return (len);
}

static char	*get_section(char *str, t_env_ctx *env)
{
	char	*section;
	int		err;

	err = 0;
	if (str[0] == '$')
		section = get_env_str(str, env);
	else if (str[0] == '"' || str[0] == '\'')
		section = get_quote_str(str);
	else
		section = get_plain_text_str(str);
	if (!section)
		return (NULL);
	if (str[0] == '"')
		err = expand_env(&section, env);
	if (!err)
		return (section);
	free(section);
	return (NULL);
}

static char	*combine(char *str1, char *str2)
{
	char	*str3;

	str3 = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (str3);
}

int	remove_quotes_and_expand_env(char **str_ref, t_env_ctx *env)
{
	size_t	i;
	char	*str;
	char	*section;

	i = 0;
	str = ft_strdup("");
	if (!str)
		return (ENOMEM);
	while ((*str_ref)[i])
	{
		section = get_section(&(*str_ref)[i], env);
		if (!section)
			return (free(str), ENOMEM);
		str = combine(str, section);
		if (!str)
			return (ENOMEM);
		i += get_section_len(&(*str_ref)[i]);
	}
	free(*str_ref);
	*str_ref = str;
	return (0);
}
