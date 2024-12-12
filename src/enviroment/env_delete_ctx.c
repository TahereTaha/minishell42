/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delete_ctx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:25:20 by gasroman          #+#    #+#             */
/*   Updated: 2024/12/10 07:36:00 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "ft_list.h"
#include "enviroment.h"
#include "minishell.h"

void	env_delete_ctx(t_env_ctx *ctx)
{
	ft_lstclear(&ctx->key_value, (t_del) del_key_value);
	free(ctx);
}
