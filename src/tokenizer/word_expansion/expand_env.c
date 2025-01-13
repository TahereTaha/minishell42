/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:17:49 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/13 13:25:50 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdlib.h>
#include <errno.h>

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

static size_t	get_section_len(char *str)
{
	size_t	len;

	if (is_env(str))
		len = get_env_len(str);
	else
		len = get_plain_text_ext1_len(str);
	return (len);
}

static char	*get_section(char *str, t_env_ctx *env)
{
	char	*section;

	if (is_env(str))
		section = get_env_str(str, env);
	else
		section = get_plain_text_ext1_str(str);
	if (!section)
		return (NULL);
	return (section);
}

static char	*combine(char *str1, char *str2)
{
	char	*str3;

	str3 = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (str3);
}

int	expand_env(char **str_ref, t_env_ctx *env)
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
