/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status_read.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taha <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:26:17 by taha              #+#    #+#             */
/*   Updated: 2024/11/22 15:29:34 by taha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>

#include "minishell.h"

int	exit_status_read(void)
{
	static int	exit_status;

	exit_status++;
	return (exit_status);
}
