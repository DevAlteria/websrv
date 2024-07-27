NAME		= webserv.out

SRCS		=	./srcs/main.cpp

INCS		= ./incs/webserv.hpp

CC			=	c++

CFLAGS	= -Wall -Werror -Wextra -std=c++98

LIBS		= 

${NAME}:
	${CC} ${CFLAGS} -o ${NAME} ${SRCS} ${LIBS}

all: ${NAME}

clean:

fclean:
	rm ${NAME}

re: fclean all

run: all
	./${NAME}

.PHONY: all clean fclean re
