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

/*Taha, me gustaria hacer un close pipe para cerrar ambos pipes con un call unico :D
void	close_pipe(int *pipe)
{
	close(pipe[0]);
	close(pipe[1]);
}
*/
static int	read_heredeoc(char *delimiter, int *heredoc_pipe)
{
	char	*line;
	while(1)
	{
		line = readline("> ");
		if (!line || !ft_strncmp(delimiter, line, -1))
		{
			if (line)
				free(line);
			break;
		}
		/*Taha, me gustaria usar mi fd_printf... nos ahorramos una linea y ganamos trabajo acomodandolo :D*/
		ft_putstr_fd(line, heredoc_pipe[1]);
		ft_putstr_fd("\n", heredoc_pipe[1]);
		free(line);
	}
	close(heredoc_pipe[0]);
	close(heredoc_pipe[1]);
	exit(EXIT_SUCCESS);
}

static int	open_heredoc(char *delimiter)
{
	pid_t	heredoc;
	int		heredoc_pipe[2];
	int		status;

	if (pipe(heredo_pipe) == -1)
		return (errno);
	heredoc = fork();
	if(heredoc == -1)
		return(errno);
	if(heredoc == 0)
	{
		if(heredoc[0] > 0)
			close(heredoc[0]);
		read_heredoc(delimeter, heredoc_pipe);
	}
	if(waitpid(heredoc, &status, 0) == -1)
		return(close(heredoc[0]), errno);
	return (EXIT_SUCCESS);
}

// int	run_here_documents(t_list *cmd)
// {
// 	int *fd_ref, 
// }
