NAME	=	libft.a

CC		=	gcc

FLAGS	=	-Wall -Werror -Wextra

HEAD	=	libft.h

LIB		=	-L. -lft

HFLAG	=	-I ${HEAD}

SRCS	=	ft_atoi.c \
 			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strrchr.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putnbr_fd.c \
			ft_putendl_fd.c \
			ft_itoa.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strmapi.c \
			ft_split.c \
			ft_strndup.c \
			ft_uitoa.c \
			ft_set.c \
			ft_itoa_base.c \
			ft_putchar.c \
			ft_putcharn.c \
			ft_putstr.c \
			ft_putstrn.c \
			ft_strncpy.c \
			ft_strcpy.c \
			ft_lltoa_base.c
SRCSB	=	ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

OBJS	=	${SRCS:.c=.o}

OBJSB	=	${SRCSB:.c=.o}

RM		=	rm -f

.c.o:
	${CC} ${FLAGS} $< -o $@ -c ${HFLAG}

${NAME}:	${OBJS}
	@ar rc ${NAME} ${OBJS}
	@ranlib ${NAME}
bonus:		${OBJSB}
	@ar rc ${NAME} ${OBJSB}
	@ranlib ${NAME}
all: 		${NAME}

clean:
	${RM} ${OBJS} ${OBJSB}
fclean:		clean
	${RM} ${NAME}
re: 	fclean all

.PHONY: clean fclean re all bonus
