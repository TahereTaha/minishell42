/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 08:08:31 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/25 19:34:44 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdio.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

static void	print_argv(char **argv)
{
	size_t	i;

	printf("this is the argv\n");
	i = 0;
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		i++;
	}
}

static void	print_redir(t_redir *redir)
{
	printf("this is one redir\n");
	if (redir->kind == WRITE_TO_FILE)
		printf("of kind: WRITE_TO_FILE\n");
	else if (redir->kind == APPEND_TO_FILE)
		printf("of kind: APPEND_TO_FILE\n");
	else if (redir->kind == READ_FROM_FILE)
		printf("of kind: READ_FROM_FILE\n");
	else if (redir->kind == HERE_DOCUMENT)
		printf("of kind: HERE_DOCUMENT\n");
	printf("the str is: %s\n", redir->str);
	printf("and the fd is: %i\n", redir->fd);
}

static void	print_redir_list(t_list *redir)
{
	t_list	*node;
	size_t	i;

	printf("printing the redir list\n\n");
	i = 0;
	node = redir;
	while (node)
	{
		printf("this is the n: $i element in the redir list\n");
		print_redir(node->content);
		i++;
		node = node->next;
	}
}

static void	print_cmd(t_cmd *cmd)
{
	printf("\t\t\tthis is a cmd\n");
	print_argv(cmd->argv);
	print_redir_list(cmd->redir);
	printf("the pipe front is: %i\n", cmd->pipe_front);
	printf("the pipe back is: %i\n", cmd->pipe_back);
	printf("\n\n");
}

void	print_cmd_list(t_list *cmd)
{
	t_list	*node;
	size_t	i;

	printf("\t\t\t\tprinting the hole cmd list\n");
	node = cmd;
	i = 0;
	while (node)
	{
		printf("\t\tthis is the n: $i element in the cmd list\n\n");
		print_cmd(node->content);
		i++;
		node = node->next;
	}
}
