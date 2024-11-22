/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatahere <tatahere@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:53:33 by tatahere          #+#    #+#             */
/*   Updated: 2024/11/22 14:37:18 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <aio.h>

# include "ft_list.h"

# define MINISHELL 42

//======  general  ======//

int		prompt(void);
int		run_command(char *cmd);

//======  enviroment  ======//

int		env_read(char **value_ref, char *key);

//======  tokenizer  ======//

typedef enum e_token_kind
{
	WORD,
	REDIRECTION,
	PIPE,
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

int		lexer(t_list **token_list_ref, char *cmd);

int		make_word_token(t_list **node_ref, char *str);
int		make_pipe_token(t_list **node_ref);
int		make_redirection_token(t_list **node_ref, char *str);

//	some utils

int	is_redir(t_list *node);

int	is_word(t_list *node);

int	is_pipe(t_list *node);

int	is_here_document(t_list *node);

//	second sintax error check:
//		check no empty pipe sections
//		check no empty redirections
int		check_sintax_error_2nd(t_list *token);

void	free_token(t_token *token);
void	print_token_list(t_list *token);

//	word_expansion

char	*get_quote_str(char *str);
size_t	get_quote_len(char *str);

char	*get_env_str(char *str);
size_t	get_env_len(char *str);

char	*get_char_str(char *str);
size_t	get_char_len(char *str);

char	*get_quoted_char_str(char *str);
size_t	get_quoted_char_len(char *str);

int		expand_word(char **str_ref);

int		expand_quoted_word(char **str_ref);

int		expand_token_list(t_list *token);

//======  executer  ======//

//	redirection


//======  error handeling  ======//

typedef enum e_minishell_errors
{
	SYNTAX_ERROR = 140,
	NO_ENV_KEY,
}	t_minishell_errors;

void	manage_error(int err);

#endif
