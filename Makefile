NAME	=	libftprintf.a
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra
HEAD	=	ft_printf.h
LIB		=	-L. -lft
LIBPDIR	=	libft/
LIBPNAME=	libft.a
HFLAG	=	-I ${HEAD}
SRCS	=	ft_prep.c \
			ft_print_char.c \
			ft_print_int.c \
			ft_print_string.c \
			ft_printf_parser.c \
			ft_printf.c \
			ft_sign.c \
			ft_space.c \
			ft_print_hexa.c \
			ft_print_unsigned.c \
			ft_print_ptr.c \
			ft_print_spec.c

OBJS	=	${SRCS:.c=.o}
.c.o:
	${CC} ${FLAGS} $< -o $@ -c ${HFLAG}

${NAME}:	${OBJS}
	@make -C ${LIBPDIR}
	@cp ${LIBPDIR}${LIBPNAME} .
	@mv ${LIBPNAME} ${NAME}
	@ar rc ${NAME} ${OBJS}
	@ranlib ${NAME}
all: 		${NAME}

clean:
	@rm -f ${OBJS}
	@make -C ${LIBPDIR} clean
fclean:		clean
	@rm -f ${NAME}
	@make -C ${LIBPDIR} fclean
re: 	fclean all

.PHONY: clean fclean re all bonus
