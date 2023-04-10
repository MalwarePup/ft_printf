# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 13:16:40 by ladloff           #+#    #+#              #
#    Updated: 2023/04/10 12:11:29 by ladloff          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		?=	libftprintf.a

SRC_DIR		?=	./src
OBJ_DIR		?=	./obj
INC_DIR		?=	./include
LIB_DIR		?=	./libft

SRCS 		:=	ft_printf.c			\
				ft_printf_utils.c	\

OBJS		:=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
LIB_INC		:=	$(addprefix -I, $(LIB_DIR)/include)
INC			:=	$(addprefix -I, $(INC_DIR))

CFLAGS		:= -Wall -Wextra -Werror $(INC) $(LIB_INC)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) -C libft
	cp $(LIB_DIR)/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(MAKE) clean -C libft
	rm -rf $(OBJS)

fclean: clean
	$(MAKE) fclean -C libft
	rm -rf $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re debug
