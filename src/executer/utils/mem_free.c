/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:11:48 by gasroman          #+#    #+#             */
/*   Updated: 2025/01/11 11:23:54 by gasroman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	double_free(char **ptr, char **_ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	if (_ptr && *_ptr)
	{
		free(*_ptr);
		*_ptr = NULL;
	}
	return (EXIT_SUCCESS);
}
