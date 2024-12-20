/* ************************************************************************** */
/*																			  */
/*														  :::      ::::::::   */
/*   env_create_ctx.c                                   :+:      :+:    :+:   */
/*													  +:+ +:+		   +:+	  */
/*   By: gasroman <gasroman@student.42.fr>		    +#+  +:+	    +#+		  */
/*												  +#+#+#+#+#+    +#+		  */
/*   Created: 2024/11/27 11:06:30 by gasroman		   #+#	  #+#			  */
/*   Updated: 2024/12/19 14:39:08 by tatahere         ###   ########.fr       */
/*																			  */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "ft_list.h"
#include "enviroment.h"
#include "minishell.h"

static t_key_value	*make_pair(char *str)
{
	char		*key;
	char		*value;
	t_key_value	*pair;
	size_t		start;
	size_t		len;

	len = ft_strchr(str, '=') - str;
	key = ft_substr(str, 0, len);
	start = len + 1;
	len = ft_strlen(&str[start]);
	value = ft_substr(str, start, len);
	if (!key || !value)
	{
		free(key);
		free(value);
		return (NULL);
	}
	pair = make_key_value(key, value);
	free(key);
	free(value);
	if (!pair)
		return (NULL);
	return (pair);
}

static t_list	*make_key_value_of_env(char **env)
{
	int			i;
	t_list		*list;
	t_list		*node;
	t_key_value	*pair;

	list = NULL;
	i = 0;
	while (env[i])
	{
		pair = make_pair(env[i]);
		if (!pair)
			return (ft_lstclear(&list, (t_del) del_key_value), NULL);
		node = ft_lstnew(pair);
		if (!node)
		{
			del_key_value(pair);
			ft_lstclear(&list, (t_del) del_key_value);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
		i++;
	}
	return (list);
}

t_env_ctx	*env_create_ctx(char **env)
{
	t_env_ctx	*env_ctx;

	env_ctx = ft_calloc(sizeof(t_env_ctx), 1);
	if (!env_ctx)
		return (NULL);
	env_ctx->key_value = make_key_value_of_env(env);
	if (!env_ctx->key_value && env[0])
	{
		free(env_ctx);
		return (NULL);
	}
	return (env_ctx);
}
