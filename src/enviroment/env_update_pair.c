/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_update_pair.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:56:41 by gasroman          #+#    #+#             */
/*   Updated: 2024/11/27 15:56:56 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_update_pair(char **data, const char *new_data)
{
	char	*swap;

	if (new_data)
	{
		swap = ft_strdup(new_data);
		if (!swap)
			return (ENV_ERR_MEM_ALLOC);
	}
	free(*data);
	*data = swap;
	return (ENV_SUCCESS);
}
