/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:05:32 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/23 16:41:12 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"
#include "enviroment.h"

// int	env_read(char **value_ref, char *key)
// {
// 	char *val;

// 	if (key[0] == 't')
// 	{
// 		val = ft_strdup("");
// 		*value_ref = val;
// 		return (NO_ENV_KEY);
// 	}
// 	val = ft_strdup(key);
// 	if (!val)
// 		return (ENOMEM);
// 	*value_ref = val;
// 	return (0);
// }

int	env_read(t_env_ctx *ctx, char **return_ref, char *key)
{
	t_key_value	*pair;
	char		*cpy_value;

	*return_ref = NULL;
	pair = get_key_pair(ctx, key);
	if (!pair)
		return (NO_ENV_KEY);
	if (pair && !pair->value)
		return (NO_ENV_VAL);
	cpy_value = ft_strdup(pair->value);
	if (!cpy_value)
		return (ENOMEM);
	*return_ref = cpy_value;
	return (0);
}
