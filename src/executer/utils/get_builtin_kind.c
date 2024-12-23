/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin_kind.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:57:56 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/23 17:54:54 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"
#include "minishell.h"

int		get_builtin_kind(char *cmd_name)
{
	int	i;

	i = 0;
	while (i < BUILTIN_NUMBER)
	{
		if (ft_strncmp(cmd_name, g_builtin_name[i], -1) == 0)
			return (i + 1);
		i++;
	}
	return (NO_BUILTIN);
}

