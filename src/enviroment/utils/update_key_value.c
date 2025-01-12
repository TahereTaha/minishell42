/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_key_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 06:34:08 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/12 17:51:53 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <errno.h>

#include "libft.h"
#include "minishell.h"
#include "enviroment.h"

int	update_key_value(t_key_value *pair, char *new_value)
{
	char	*cpy_value;

	cpy_value = ft_strdup(new_value);
	if (!cpy_value)
		return (ENOMEM);
	free(pair->value);
	pair->value = cpy_value;
	return (0);
}
