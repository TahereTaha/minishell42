# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gasroman <gasroman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 17:26:50 by gasroman          #+#    #+#              #
#    Updated: 2024/11/22 14:40:07 by tatahere         ###   ########.fr        #
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

OBJS			+=	$(OBJS_MAIN)

OBJS_ENV		:=	env_read.o						\

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
					char.o							\
					quoted_char.o					\
					env.o							\
					quote.o							\
					expand_token_list.o				\
					expand_word.o					\
					expand_quoted_word.o			\

OBJS			+=	$(OBJS_TOKENIZER)

OBJS			:=	$(addprefix $(BIN_DIR), $(OBJS))
DEPS			:=	$(OBJS:.o=.d)

VPATH			+=	src
VPATH			+=	:src/tokenizer
VPATH			+=	:src/tokenizer/lexer
VPATH			+=	:src/tokenizer/word_expansion
VPATH			+=	:src/enviroment

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
