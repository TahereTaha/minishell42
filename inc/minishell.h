/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:53:33 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/19 20:39:49 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "ft_list.h"

# define MINISHELL 42

typedef enum e_minishell_errors
{
	SYNTAX_ERROR = 150,
}	t_minishell_errors;

//======  general  ======//

int	prompt(void);
int	run_command(char *cmd);

//======  enviroment  ======//

//	things

//======  tokenizer  ======//

typedef enum e_token_kind
{
	WORD,
	REDIRECTION,
	PIPE,
	TERMINAL_TOKEN,
}	t_token_kind;

typedef struct s_token
{
	t_token_kind	kind;
	char			*str;
}	t_token;

int		tokenize(t_list **token_list_ref, char *cmd);

//	first sintax error check:
//		check unvalanced quotes
int		check_sintax_error_1st(char *str);

//	second sintax error check:
//		check no empty pipe sections
//		check no empty redirections
int		check_sintax_error_2nd(t_list *token);

void	free_token(t_token *token);

//======  word_expansion  ======//

//======  executer  ======//

//======  redirection  ======//

#endif
