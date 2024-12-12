/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_key_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 06:26:36 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/10 06:33:14 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "minishell.h"
#include "enviroment.h"

t_key_value	*make_key_value(char *key, char *value)
{
	char		*cpy_key;
	char		*cpy_value;
	t_key_value	*pair;

	pair = ft_calloc(sizeof(t_key_value), 1);
	cpy_key = ft_strdup(key);
	cpy_value = ft_strdup(value);
	if (!pair || !cpy_key || cpy_value)
	{
		free(pair);
		free(cpy_key);
		free(cpy_value);
		return (NULL);
	}
	pair->key = cpy_key;
	pair->value = cpy_value;
	return (pair);
}
