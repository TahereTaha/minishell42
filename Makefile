# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 17:26:50 by gasroman          #+#    #+#              #
#    Updated: 2024/12/20 14:49:41 by tatahere         ###   ########.fr        #
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
CDEBUG			+=	-g -fsanitize=address
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

OBJS_EXECUTER	:=	execute_cmd.o					\
					make_argv.o						\
					make_cmd.o						\
					make_cmd_list.o					\
					make_redir.o					\
					print_cmd_list.o				\

OBJS			+=	$(OBJS_EXECUTER)

OBJS			:=	$(addprefix $(BIN_DIR), $(OBJS))
DEPS			:=	$(OBJS:.o=.d)

VPATH			+=	src
VPATH			+=	:src/tokenizer
VPATH			+=	:src/tokenizer/lexer
VPATH			+=	:src/tokenizer/word_expansion
VPATH			+=	:src/tokenizer/word_expansion/utils
VPATH			+=	:src/enviroment
VPATH			+=	:src/enviroment/utils
VPATH			+=	:src/executer
VPATH			+=	:src/executer/preparation

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
