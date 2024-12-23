/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cmd_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 08:08:31 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/23 17:50:54 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"
#include "ft_list.h"
#include "minishell.h"

static void	print_argv(char **argv)
{
	size_t	i;

	printf("\tthis is the argv\n");
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

	printf("\tprinting the redir list\n\n");
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

static void	print_cmd_kind(char *cmd, t_env_ctx *env)
{
	t_builtin_kind	kind;
	char			*pathname;
	int				err;

	err = 0;
	kind = get_builtin_kind(cmd);
	if (kind == 0)
	{
		printf("this is a normal cmd\n");
		pathname = path_finder(&err, cmd, env);
		if (err == NO_CMD)
			printf("command not found\n");
		if (err == NO_FILE_OR_DIR)
			printf("file or directiory not found\n");
		if (err == NO_PERMISION_CMD)
			printf("you don't have permision to execute this command\n");
		if (err == NO_FILE_NAME_ARG)
			printf("this is not a filename argument\n");
		if (!err)
			printf("the pathname is %s\n", pathname);
		free(pathname);
	}
	else
	{
		printf("this is a builtin\n");
		printf("this is the %s builtin\n", g_builtin_name[kind - 1]);
	}

}

static void	print_cmd(t_cmd *cmd, t_env_ctx *env)
{
	printf("\t\t\tthis is a cmd\n");
	print_cmd_kind(cmd->argv[0], env);
	print_argv(cmd->argv);
	print_redir_list(cmd->redir);
	printf("\n\n");
}

void	print_cmd_list(t_list *cmd, t_env_ctx *env)
{
	t_list	*node;
	size_t	i;

	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\tprinting the hole cmd list\n\n\n");
	node = cmd;
	i = 0;
	while (node)
	{
		printf("\t\tthis is the n: $%zu element in the cmd list\n\n", i);
		print_cmd(node->content, env);
		i++;
		node = node->next;
	}
}
