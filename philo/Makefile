CC = cc
CFLAGS = -Wall -Wextra -Werror
INCDIR = includes
SRC = $(wildcard srcs/*.c)
OBJ = $(SRC:%.c=%.o)
NAME = philosopher

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(CLIENT)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

clean:
	rm -f $(COBJ) $(SOBJ)

fclean: clean
	rm -f client server

re: fclean all

.PHONY: all clean fclean re
