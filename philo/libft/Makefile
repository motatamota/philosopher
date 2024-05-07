CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = .
INCDIR = .
SRC = ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strnstr.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_striteri.c
OBJ = $(SRC:%.c=%.o)
BONUSDIR = .
BONUS = ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c
BONUSOBJ = $(BONUS:%.c=%.o)
NAME = libft.a

all: $(NAME)
$(NAME): $(OBJ)
	ar rcs $@ $^
$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@
bonus: $(BONUSOBJ)
	touch bonus
	ar rcs $(NAME) $^
$(BONUSDIR)/%.o: $(BONUSDIR)/%.c
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@
clean:
	rm -f $(OBJ) $(BONUSOBJ) bonus
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
