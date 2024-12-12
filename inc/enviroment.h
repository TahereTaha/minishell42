/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 06:20:50 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/10 08:41:09 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIROMENT_H
# define ENVIROMENT_H

# include "minishell.h"

t_key_value	*make_key_value(char *key, char *value);
int			update_key_value(t_key_value *pair, char *new_value);
void		del_key_value(t_key_value *pair);

t_key_value	*get_key_pair(t_env_ctx *ctx, char *key);

#endif
