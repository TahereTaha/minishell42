/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:05:32 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/22 13:58:41 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "libft.h"
#include "minishell.h"

int	env_read(char **value_ref, char *key)
{
	char *val;

	if (key[0] == 't')
	{
		val = ft_strdup("");
		*value_ref = val;
		return (NO_ENV_KEY);
	}
	val = ft_strdup(key);
	if (!val)
		return (ENOMEM);
	*value_ref = val;
	return (0);
}
