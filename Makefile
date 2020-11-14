NAME	=	libftprintf.a

CC		=	gcc

FLAGS	=	-Wall -Werror -Wextra

HEAD	=	ft_printf.h

LIB		=	-L. -lft

HFLAG	=	-I ${HEAD}

SRCS	=	ft_prep.c \
			ft_print_char.c \
			ft_print_int.c \
			ft_print_string.c \
			ft_printf_parser.c \
			ft_printf.c \
			ft_sign.c \
			ft_space.c \
			ft_putchar.c \
			ft_putcharn.c \
			ft_putstr.c \
			ft_putstrn.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_atoi.c \
			ft_strncpy.c \
			ft_bzero.c \
			ft_strlen.c \
			ft_isdigit.c \
			ft_strcpy.c \
			ft_strndup.c \
			ft_uitoa.c \
			ft_set.c \
			ft_memset.c \
			ft_calloc.c
OBJS	=	${SRCS:.c=.o}

RM		=	rm -f

.c.o:
	${CC} ${FLAGS} $< -o $@ -c ${HFLAG}

${NAME}:	${OBJS}
	@ar rc ${NAME} ${OBJS}
	@ranlib ${NAME}
all: 		${NAME}

clean:
	${RM} ${OBJS} ${OBJSB}
fclean:		clean
	${RM} ${NAME}
re: 	fclean all

.PHONY: clean fclean re all bonus
