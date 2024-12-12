/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:20:57 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/26 16:49:58 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <readline/readline.h>

#include "libft.h"
#include "ft_list.h"

static int	here_document(int *fd_ref, char *delimiter)
{
	char	*line;
	int		here_document_pipe[2];

	if (pipe(here_document_pipe) == -1)
		return (errno);
	line = ft_strdup("");
	if (!line)
		return (errno);
	while (ft_strncmp(delimiter, line, -1))
	{
		if (write(here_document_pipe[1], line, ft_strlen(line)) == -1)
			return (errno);
		free(line);
		line = readline
	}
}

int	run_here_documents(t_list *cmd)
{

}
