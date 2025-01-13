# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 17:26:50 by gasroman          #+#    #+#              #
#    Updated: 2025/01/13 10:34:59 by tatahere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT_DIR = ./

# ============================ important directories ========================= #

#	ROOT_DIR shoud be defined alredy
BIN_DIR = $(ROOT_DIR)/bin/
INC_DIR = $(ROOT_DIR)/inc/

# ============================ commands ====================================== #

AR				=	ar -rcs
CC				=	cc
RM				=	rm -rf

# ============================ libs ========================================== #

#	libft
LIBFT_DIR		=	$(ROOT_DIR)libft/
LIBFT			=	$(LIBFT_DIR)libft.a
LIBS			+=	$(LIBFT)

#	readline
#  == some day there will be something here ==  #

# ============================ cflags ======================================== #

CFLAGS			+=	-Wall -Wextra -Werror

#	dependencies
CFLAGS			+=	-MMD

#	includes
#	the CINC (c includes)
#		can be defined previously to take into acount the local headers
CINC			+=	-I$(LIBFT_DIR)/inc 
CINC			+=	-I$(INC_DIR) 
CFLAGS			+=	$(CINC)

#	debug
CDEBUG			+=	#-g -fsanitize=address
CFLAGS			+=	$(CDEBUG)

# ============================ files ========================================= #

OBJS_MAIN		:=	main.o							\
					prompt.o						\
					run_command.o					\
					manage_error.o					\
					utils.o							\

OBJS			+=	$(OBJS_MAIN)

OBJS_ENV		:=	exit_status_set.o				\
					exit_status_read.o				\
					env_read.o						\
					env_set.o						\
					env_unset.o						\
					env_create_ctx.o				\
					env_delete_ctx.o				\
					del_key_value.o					\
					get_key_pair.o					\
					make_key_value.o				\
					update_key_value.o				\
					env_get_env.o					\
					env_get_export.o				\

OBJS			+=	$(OBJS_ENV)

OBJS_TOKENIZER	:=	tokenizer.o						\
					check_sintax_error_1st.o		\
					check_sintax_error_2nd.o		\
					tokenizer_utils.o				\
					free_token.o					\
					lexer.o							\
					make_pipe_token.o				\
					make_redirection_token.o		\
					make_word_token.o				\
					print_token_list.o				\

OBJS			+=	$(OBJS_TOKENIZER)

OBJS_EXPANSER	:=	plain_text.o					\
					plain_text_ext1.o				\
					plain_text_ext2.o				\
					env.o							\
					quote.o							\
					expand_env.o					\
					remove_quotes.o					\
					remove_quotes_and_expand_env.o	\
					remove_quotes_and_expand_list.o	\

OBJS			+=	$(OBJS_EXPANSER)

OBJS_PREP		:=	make_argv.o						\
					make_cmd.o						\
					make_cmd_list.o					\
					make_redir.o					\
					print_cmd_list.o				\

OBJS			+=	$(OBJS_PREP)

OBJS_EXECUTER	:=	execute_cmd.o					\
					get_builtin_kind.o				\
					path_finder.o					\
					execute_simple_command.o		\
					execute_command.o				\
					execute_pipe.o					\
					execute_simple_builtin.o		\
					execute_piped_builtin.o			\
					redirections.o					\
					list_ext.o						\
					pipe_utils.o					\
					restore_input_output.o			\
					here_document.o					\
					mem_free.o						\

OBJS			+=	$(OBJS_EXECUTER)

OBJS_BUILTIN	:=	builtin_echo.o					\
					builtin_pwd.o					\
					builtin_export.o				\
					builtin_unset.o					\
					builtin_env.o					\
					builtin_exit.o					\
					builtin_cd.o					\

OBJS			+=	$(OBJS_BUILTIN)

OBJS_SIGNAL		:=	signals.o						\

OBJS			+=	$(OBJS_SIGNAL)

OBJS			:=	$(addprefix $(BIN_DIR), $(OBJS))
DEPS			:=	$(OBJS:.o=.d)

VPATH			+=	src
VPATH			+=	:src/tokenizer
VPATH			+=	:src/tokenizer/lexer
VPATH			+=	:src/tokenizer/word_expansion
VPATH			+=	:src/tokenizer/word_expansion/utils
VPATH			+=	:src/tokenizer/preparation
VPATH			+=	:src/enviroment
VPATH			+=	:src/enviroment/utils
VPATH			+=	:src/executer
VPATH			+=	:src/executer/utils
VPATH			+=	:src/executer/builtin
VPATH			+=	:src/executer/here_document
VPATH			+=	:src/signals

# =========================== rules ========================================= #

NAME			=	minishell

all: libs $(BIN_DIR) $(NAME)

libs:
	git submodule init
	git submodule update
	make -C $(LIBFT_DIR) bonus

$(BIN_DIR):
	mkdir $(BIN_DIR)

$(NAME): $(OBJS) $(MODULE_ARCHIVE) $(LIBS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBS) -L/usr/local/lib -lreadline

$(BIN_DIR)%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) bin
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re libs
-include $(DEPS)
