# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 13:16:40 by ladloff           #+#    #+#              #
#    Updated: 2023/06/15 20:22:25 by ladloff          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL		:=	/bin/sh

NAME		:=	libftprintf.a

SRC_DIR		:=	./src
BUILD_DIR	:=	./build
INCLUDE_DIR	:=	./include
LIBFT_DIR	:=	./lib/libft

SRC_FILES 		:=	ft_printf.c \
					ft_printf_utils.c
OBJ_FILES	:=	$(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

CFLAGS		:=	-Wall -Wextra -Werror -Wpedantic -MMD -MP
CPPFLAGS	:=	-I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include

.PHONY: all lib clean fclean re cleanlib fcleanlib relib

all: lib $(NAME)

lib:
	$(MAKE) -C $(LIBFT_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

-include $(OBJ_FILES:.o=.d)

$(NAME): $(OBJ_FILES)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJ_FILES)

clean:
	rm -rf $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

cleanlib:
	$(MAKE) clean -C $(LIBFT_DIR)

fcleanlib:
	$(MAKE) fclean -C $(LIBFT_DIR)

relib: fcleanlib lib
