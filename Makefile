NAME = fillit

CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I libft/

SRC = main.c \
	file.c \
	parser.c \
	utils.c \
	checker.c \
	solve.c \

LIBFT = libft/libft.a

.PHONY = all clean fclean clean re

all: $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT)
	@gcc $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
	@echo "\033[32mCompiled Executable\033[0m"

clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all

# gcc libft/libft.a *.c -Wall -Werror -Wextra -I libft 