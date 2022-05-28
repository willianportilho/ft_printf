# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:44:36 by wportilh          #+#    #+#              #
#    Updated: 2022/05/28 04:57:06 by wportilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=                      \
			./src/ft_printf.c   \
			./src/ft_putchar.c   \
			./src/ft_putnbr_uns.c \
			./src/ft_putnbr.c      \
			./src/ft_putstr.c       \
			./src/ft_uitohex_p.c     \
			./src/ft_uitohex_up.c     \
			./src/ft_uitohex.c         \
			./src/pre_char.c            \
			./src/pre_nbr_uns.c          \
			./src/pre_nbr.c               \
			./src/pre_p.c                  \
			./src/pre_str.c                 \
			./src/pre_x_lower.c              \
			./src/pre_x_upper.c               \

OBJ		= ${SRC:.c=.o}

NAME		= libftprintf.a

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

CREATE		= ar rc

RM			= rm -f

${NAME}:	${OBJ}
			${CREATE} ${NAME} ${OBJ}

.c.o:		
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:		${NAME}

clean:
			${RM} ${OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re