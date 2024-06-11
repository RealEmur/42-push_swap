NAME = push_swap

SRCS = push_swap.c helpers/parser.c utils/del_list.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = lib/libft/
LIBFT_NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): libft $(OBJS)
	$(CC) $(OBJS) $(LIBFT_DIR)$(LIBFT_NAME) -o $(NAME)

libft:
	make -C $(LIBFT_DIR)

clean: 
	rm -rf $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all