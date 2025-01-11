/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:53:33 by tatahere          #+#    #+#             */
/*   Updated: 2025/01/11 21:56:50 by tatahere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <aio.h>

# include "ft_list.h"


extern int	g_signal_num;

void	handle_interactive(int signal_num);
void	handle_non_interactive(int signal_num);

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

char		**env_get_env(t_env_ctx *ctx);
char		**env_get_export(t_env_ctx *ctx);

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

int		execute_cmd(t_list *token, t_env_ctx *env);

typedef enum e_redir_kind
{
	WRITE_TO_FILE,
	APPEND_TO_FILE,
	READ_FROM_FILE,
	HERE_DOCUMENT,
	PIPE_FRONT,
	PIPE_BACK,
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
}	t_cmd;


//	this is for converting the token list to command list
int		make_redir(t_list *token, t_list **redir_list_ref);
void	free_redir(t_redir *redir);
char	**make_argv(t_list *token);
t_cmd	*make_cmd(t_list *token);
void	free_cmd(t_cmd *cmd);

//	this will free the token
t_list	*make_cmd_list(t_list *token);

void	print_cmd_list(t_list *cmd, t_env_ctx *env);

//	heredoc
int	run_here_doc(t_list *redir, t_env_ctx *env);

//	builtin

typedef enum e_builtin_kind
{
	NO_BUILTIN = 0,
	ECHO,
	PWD,
}	t_builtin_kind;

# define BUILTIN_NUMBER 6

# include <stdlib.h>

int		builtin_echo(t_cmd *cmd);
int		builtin_pwd(void);
int		builtin_export(t_cmd *cmd, t_env_ctx *env);
int		builtin_unset(t_cmd *cmd, t_env_ctx *env);
int		builtin_env(t_cmd *cmd, t_env_ctx *env);
int		builtin_exit(t_cmd *cmd, t_env_ctx *env);

const static char	*g_builtin_name[] = {"echo","pwd", "export", \
	"unset", "env", "exit"};

typedef int (*t_builtin)(t_cmd *, t_env_ctx *);

const static t_builtin g_builtins[] = \
{\
	(t_builtin) &builtin_echo, \
	(t_builtin) &builtin_pwd, \
	(t_builtin) &builtin_export, \
	(t_builtin) &builtin_unset, \
	(t_builtin) &builtin_env, \
	(t_builtin) &builtin_exit, \
	(t_builtin) NULL \
};

//	executor helper functions

int		get_builtin_kind(char *cmd_name);
char	*path_finder(int *err_ref, char *cmd_name, t_env_ctx *env);
void	free_strs(char **strs);

//	executor (execv)

# include <sys/types.h>
# include <unistd.h>

//	utils

typedef struct s_struct_pipe{
	int	front[2];
	int	back[2];
}	t_struct_pipe;

void	init_pipe(t_struct_pipe *pipe);
void	print_cmd(t_cmd *cmd, t_env_ctx *env);
void	*ft_lstpurge(t_list **lst, void (*del)(void*), size_t index);
void	move_pipe_back(t_struct_pipe *pipe);
void	close_pipe(int *pipe);
void	hook_to_pipe(int *pipe_front, int *pipe_back);

int		handle_redirection(t_list *redir);
void	save_in_out(int *in_out);
void	reset_in_out(int *in_out);

int		execute_simple_command(t_list *cmd, t_env_ctx *env);
int		execute_pipe(t_list *cmd, t_env_ctx *env);

int		execute_simple_builtin(t_cmd *cmd, t_env_ctx *env, int kind);
int		execute_piped_builtin(t_cmd *cmd, t_env_ctx *env, int kind);
int		execute_command(t_cmd *cmd, t_env_ctx *env);

int		double_free(char **ptr, char **_ptr);

void	handle_siginth(int sig);
int		get_break_it(int flag, int value);
void	break_it(int signal);
void	_sigint(int sig);
int		get_status(int flag, int value);
void	handle_signaled(int *status, int signal);

//======  error handeling  ======//

typedef enum e_minishell_errors
{
	SYNTAX_ERROR = 140,
	NO_ENV_KEY,
	NO_ENV_VAL,
	NO_VALID_KEY,
	NO_CMD,
	NO_FOUND_CMD,
	NO_FILE_OR_DIR,
	NO_PERMISION_CMD,
	NO_FILE_NAME_ARG,
}	t_minishell_errors;

void	manage_error(int err);

#endif
