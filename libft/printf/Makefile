NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c printf_utilites.c
OBJS = ${SRC:.c=.o}

all: ${NAME}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	ar rcs $(NAME) ${OBJS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re