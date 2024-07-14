NAME = push_swap
SRCS = push_swap.c helpers/parser.c helpers/actions.c helpers/sort.c helpers/calc_actions.c \
       utils/stack_node_utils.c utils/stack_utils.c utils/actions.c utils/functions.c 


BONUS_NAME = checker
BONUS_SRCS = bonus/checker_bonus.c bonus/helpers/parser_bonus.c bonus/utils/stack_utils_bonus.c bonus/utils/actions_bonus.c

LIBFT_NAME = libft.a
LIBFT_DIR = lib/libft
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(SRCS)
	$(CC) $(SRCS) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS_SRCS)
	$(CC) $(BONUS_SRCS) $(LIBFT) -o $(BONUS_NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR) 

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all