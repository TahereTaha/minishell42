/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:20:10 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/25 20:40:28 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

static size_t	argv_len(t_list *token)
{
	size_t	len;
	t_list	*current;

	len = 0;
	current = token;
	while (current && !is_pipe(current))
	{
		if (is_word(current))
			len++;
		if (is_redir(current))
			current = current->next->next;
		else
			current = current->next;
	}
	return (len);
}

char	**make_argv(t_list *token)
{
	t_list	*current;
	size_t	i;
	char	**argv;

	argv = ft_calloc(sizeof(char *), argv_len(token) + 1);
	if (!argv)
		return (NULL);
	i = 0;
	current = token;
	while (current && !is_pipe(current))
	{
		while (current && is_redir(current))
			current = current->next->next;
		if (!current || is_pipe(current))
			break ;
		argv[i] = ft_strdup(((t_token *)current->content)->str);
		if (!argv[i])
			return (free_strs(argv), NULL);
		i++;
		current = current->next;
	}
	return (argv);
}
