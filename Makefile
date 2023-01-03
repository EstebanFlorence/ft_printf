# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 09:30:07 by adi-nata          #+#    #+#              #
#    Updated: 2023/01/03 16:26:56 by adi-nata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	=	sources/ft_printf.c\
				sources/syntax.c\
				sources/checkflags.c\
				sources/printftools1.c\
				sources/printftools2.c\
				sources/printftools3.c\
				sources/printf_c.c\
				sources/printf_s.c\
				sources/printf_p.c\
				sources/printf_di.c\
				sources/printf_u.c\
				sources/printf_x.c\

OBJS	=	${SRCS:.c=.o}

CC	= gcc

FLAGS	= -Wall -Wextra -Werror -g

RM	= rm -f

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	cd libft/ && ${MAKE}
	ar rcs ${NAME} ${OBJS}


all: 		${NAME}

bonus:		all

clean:
			${RM} ${OBJS}
			cd libft/ && ${MAKE} clean

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:	all clean fclean re
