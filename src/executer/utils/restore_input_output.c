/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_input_output.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:29:30 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/13 10:25:36 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "libft.h"
#include "minishell.h"

int	save_in_out(int *in_out)
{
	in_out[0] = dup(0);
	if (in_out[0] == -1)
		return (errno);
	in_out[1] = dup(1);
	if (in_out[1] == -1)
		return (errno);
	return (0);
}

int	reset_in_out(int *in_out)
{
	if (dup2(in_out[0], 0) == -1)
		return (errno);
	if (dup2(in_out[1], 1) == -1)
		return (errno);
	return (0);
}
