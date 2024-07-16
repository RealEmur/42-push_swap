NAME = push_swap
SRCS = push_swap.c helpers/parser.c helpers/actions.c helpers/sort.c helpers/calc_actions.c \
       utils/stack_node_utils.c utils/stack_utils.c utils/actions.c utils/functions.c 

LIBFT_NAME = libft.a
LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(SRCS)
	$(CC) $(SRCS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) -s

clean:
	make clean -C $(LIBFT_DIR) 

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all
