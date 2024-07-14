NAME = libft.a
SOURCES = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_memmove.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_striteri.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strtrim.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstdelone.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstiter.c ft_lstclear.c ft_lstmap.c
OBJS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror

PRINTF_PATH = ft_printf
PRINTF_SRCS = $(PRINTF_PATH)/ft_printf.c $(PRINTF_PATH)/utils/ft_putchar.c $(PRINTF_PATH)/handlers/handle_char.c \
			$(PRINTF_PATH)/handlers/handle_string.c $(PRINTF_PATH)/utils/ft_putstr.c $(PRINTF_PATH)/utils/print_base.c \
			$(PRINTF_PATH)/handlers/handle_hex_lower.c $(PRINTF_PATH)/handlers/handle_hex_upper.c \
			$(PRINTF_PATH)/handlers/handle_address.c $(PRINTF_PATH)/handlers/handle_int.c \
			$(PRINTF_PATH)/handlers/handle_unsigned_int.c
PRINTF_OBJS = $(PRINTF_SRCS:.c=.o)

GNL_PATH = get_next_line
GNL_SRCS = $(GNL_PATH)/get_next_line.c $(GNL_PATH)/get_next_line_utils.c
GNL_OBJS = $(GNL_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(SOURCES) $(OBJS) $(PRINTF_SRCS) $(PRINTF_OBJS) $(GNL_SRCS) $(GNL_OBJS)
	ar -rc $(NAME) $(OBJS) $(PRINTF_OBJS)

clean:
	$(RM) $(OBJS) $(PRINTF_OBJS) $(GNL_OBJS)
	
fclean: clean
	$(RM) $(NAME) 
	
re: fclean all
