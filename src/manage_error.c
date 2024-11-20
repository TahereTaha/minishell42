/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:41:30 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/20 11:07:39 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#include "libft.h"
#include "minishell.h"

static void	manage_syntax_error(void)
{
	printf("syntax error\n");
}

static void	manage_system_error(int err)
{
	perror("minishell: ");
	if (err == ENOMEM)
		exit(1);
	exit(42);
}

void	manage_error(int err)
{
	if (!err)
		return ;
	if (err != SYNTAX_ERROR)	//	if it is on errno
		manage_system_error(err);
	manage_syntax_error();
}
