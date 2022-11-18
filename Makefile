# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 13:16:40 by ladloff           #+#    #+#              #
#    Updated: 2022/11/04 20:43:18 by ladloff          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
# Macros                                                                       #
#==============================================================================#

# Main

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -I ${INCL} -I ${LIB_DIR}

# Sources

SRCS_DIR = srcs/

SRCS =	ft_printf.c			\
		ft_printchar.c		\
		ft_printstr.c		\
		ft_format.c			\
		ft_printptr.c		\
		ft_printdec.c		\
		ft_printudec.c		\
		ft_printhex_lower.c	\
		ft_printhex_upper.c

# Includes

INCL = includes/

# Objects

OBJS_DIR = objs/

OBJS = ${addprefix ${OBJS_DIR}, ${SRCS:.c=.o}}

# Libft

LIB_DIR = libft

# Others

RM = rm -rf

AR = ar -rc

#==============================================================================#
# Rules                                                                        #
#==============================================================================#

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
	@mkdir -p ${OBJS_DIR}
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): ${OBJS}
	@make -C libft
	@cp libft/libft.a ${NAME}
	@${AR} ${NAME} ${OBJS}

all: ${NAME}

clean:
	@make clean -C libft
	@${RM} ${OBJS}

fclean: clean
	@make fclean -C libft
	@${RM} ${NAME}
	@${RM} ${OBJS_DIR}

re: fclean all

.PHONY: all clean fclean re
