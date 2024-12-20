/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 20:40:25 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/20 14:52:26 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdlib.h>

#include "libft.h"
#include "minishell.h"

size_t	get_env_len(char *str)
{
	size_t	i;

	i = 1;
	if (str[i] == '?')
		return (2);
	while (ft_isalnum(str[i]))
		i++;
	return (i);
}

char	*get_env_str(char *word, t_env_ctx *env)
{
	char	*str;
	char	*key;
	size_t	len;
	int		err;

	len = get_env_len(word);
	if (word[1] != '?')
	{
		key = ft_substr(word, 1, len - 1);
		if (!key)
			return (NULL);
		err = env_read(env, &str, key);
		free(key);
		if (err && err != NO_ENV_KEY)
			return (NULL);
		return (str);
	}
	str = ft_itoa(exit_status_read(env));
	return (str);
}
