/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:47:03 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/12 17:30:59 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "libft.h"
#include "minishell.h"

void	close_pipe(int *pipe)
{
	if (pipe[0] != -1)
	{
		close(pipe[0]);
		pipe[0] = -1;
	}
	if (pipe[1] != -1)
	{
		close(pipe[1]);
		pipe[1] = -1;
	}
}

void	init_pipe(t_struct_pipe *pipe)
{
	pipe->back[0] = -1;
	pipe->back[1] = -1;
	pipe->front[0] = -1;
	pipe->front[1] = -1;
}

void	move_pipe_back(t_struct_pipe *pipe)
{
	close_pipe((int *)&pipe->back);
	ft_memmove((int *)&pipe->back, (int *)&pipe->front, sizeof(int) * 2);
	pipe->front[0] = -1;
	pipe->front[1] = -1;
}

void	hook_to_pipe(int *pipe_front, int *pipe_back)
{
	if (pipe_front[0] != -1)
		dup2(pipe_front[1], 1);
	if (pipe_back[1] != -1)
		dup2(pipe_back[0], 0);
	close_pipe(pipe_back);
	close_pipe(pipe_front);
}
