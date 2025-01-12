/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_input_output.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:29:30 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/12 17:30:02 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "libft.h"
#include "minishell.h"

void	save_in_out(int *in_out)
{
	in_out[0] = dup(0);
	in_out[1] = dup(1);
}

void	reset_in_out(int *in_out)
{
	dup2(in_out[0], 0);
	dup2(in_out[1], 1);
}
