/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_create_pair.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:57:47 by gasroman          #+#    #+#             */
/*   Updated: 2024/11/27 15:24:47 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_key_value_pair	*create_pair(const char *key, const char *value)
{
	t_key_value_pair	*new_pair;

	new_pair = malloc(sizeof(t_key_value_pair));
	if (!new_pair)
		return (ENV_ERR_MEM_ALLOC);
	new_pair->key = ft_strdup(key);
	if (value)
		new_pair->value = ft_strdup(value);
	else
		new_pair->value = NULL;
	new_pair->next = NULL;
	return (new_pair);
}
