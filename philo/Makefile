CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread
# CFLAGS = -Wall -Wextra -Werror -g
INCDIR = includes
SRC = srcs/ck.c srcs/main.c srcs/main2.c srcs/move.c srcs/thread.c srcs/ft_atoi.c srcs/ft_memcpy.c srcs/mutex.c srcs/mutex_free.c srcs/leftright.c
OBJ = $(SRC:%.c=%.o)
NAME = philosopher

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
