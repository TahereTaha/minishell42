/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:53:33 by tatahere          #+#    #+#             */
/*   Updated: 2024/12/20 15:08:35 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <aio.h>

# include "ft_list.h"

# define MINISHELL 42

//======  enviroment  ======//

typedef struct s_key_value
{
	char	*key;
	char	*value;
}	t_key_value;

typedef struct s_env_ctx
{
	t_list	*key_value;
	int		exit_status;
}	t_env_ctx;

t_env_ctx	*env_create_ctx(char **env);
void		env_delete_ctx(t_env_ctx *ctx);

int			exit_status_read(t_env_ctx *env_ctx);
void		exit_status_set(t_env_ctx *env_ctx, int new_value);

int			env_read(t_env_ctx *ctx, char **return_ref, char *key);
int			env_set(t_env_ctx *ctx, char *key, char *value);
int			env_unset(t_env_ctx *ctx, char *key);

char		*env_get_env(t_env_ctx *ctx);
char		*env_get_export(t_env_ctx *ctx);

//======  general  ======//

int		prompt(t_env_ctx *env);
int		run_command(char *cmd, t_env_ctx *env);

//	utils
void	free_strs(char **strs);

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

int		tokenize(t_list **token_list_ref, char *cmd, t_env_ctx *env);

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

//	this will return the string inside the quotes
char	*get_quote_str(char *str);
size_t	get_quote_len(char *str);

//	this will return the value of the enviroment variable
char	*get_env_str(char *str, t_env_ctx *env);
size_t	get_env_len(char *str);

//	this will return the string in between the above two.
//	between get_quote and get_env
char	*get_plain_text_str(char *str);
size_t	get_plain_text_len(char *str);

//	this will include the quote characters in the plain text
char	*get_plain_text_ext1_str(char *str);
size_t	get_plain_text_ext1_len(char *str);

//	this will include the $ characters in the plain text
char	*get_plain_text_ext2_str(char *str);
size_t	get_plain_text_ext2_len(char *str);

int		remove_quotes(char **str_ref);
int		expand_env(char **str_ref, t_env_ctx *env);
int		remove_quotes_and_expand_env(char **str_ref, t_env_ctx *env);

int		remove_quote_and_expand_list(t_list *token, t_env_ctx *env);

//======  executer  ======//

typedef enum e_redir_kind
{
	WRITE_TO_FILE,
	APPEND_TO_FILE,
	READ_FROM_FILE,
	HERE_DOCUMENT,
}	t_redir_kind;

typedef struct s_redir
{
	t_redir_kind	kind;
	char			*str;
	int				fd;
}	t_redir;

typedef struct	s_cmd
{
	char	**argv;
	t_list	*redir;
	int		pipe_front;
	int		pipe_back;
}	t_cmd;

const static char	*g_built_in_name[] = {"echo","pwd"};

//	this is for converting the token list to command list
int		make_redir(t_list *token, t_list **redir_list_ref);
void	free_redir(t_redir *redir);
char	**make_argv(t_list *token);
t_cmd	*make_cmd(t_list *token);
void	free_cmd(t_cmd *cmd);

//	this will free the token
t_list	*make_cmd_list(t_list *token);

void	print_cmd_list(t_list *cmd);

int		run_here_documents(t_list *cmd);

int		execute_simple_cmd(t_cmd *cmd);
int		execute_program(t_cmd *cmd);
int		execute_builtin(t_cmd *cmd);

//int		execute_pipe(t_list *cmd);

int		execute_cmd(t_list *token);

//======  error handeling  ======//

typedef enum e_minishell_errors
{
	SYNTAX_ERROR = 140,
	NO_ENV_KEY,
}	t_minishell_errors;

void	manage_error(int err);

#endif
