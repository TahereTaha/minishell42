/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_key_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 06:37:59 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/10 06:40:12 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "minishell.h"
#include "enviroment.h"

void	del_key_value(t_key_value *pair)
{
	free(pair->value);
	free(pair->key);
	free(pair);
}
