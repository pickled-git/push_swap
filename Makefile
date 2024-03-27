NAME	= push_swap

SRCDIR	= src
INCDIR	= include

SRC		= 	main.c stack_exit.c stack_init.c \
			stack_utils.c
SRCS	= $(addprefix $(SRCDIR)/, $(SRC))
OBJS	= $(SRCS:.c=.o)

LIBFT = libft/libft.a
LIBFT_PATH = libft/
LIBFT_INCLUDE = libft/include

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBFT_INCLUDE) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all


.PHONY: all clean fclean re