CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCDIR = includes
SRC = srcs/ck.c srcs/main.c srcs/main2.c srcs/move.c srcs/thread.c
OBJ = $(SRC:%.c=%.o)
NAME = philosopher

all: $(NAME)

$(NAME): $(OBJ) libft/libft.a
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

libft/libft.a:
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
