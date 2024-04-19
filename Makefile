NAME	= push_swap

SRCDIR	= src
INCDIR	= include

SRC		= 	main.c stack/stack_exit.c stack/stack_init.c stack/stack_utils.c \
			operations/swap.c operations/push.c operations/rotate.c \
			operations/reverse_rotate.c sort/sort.c sort/assign_indexes.c \
			sort/advance_sort.c sort/sort_utils.c
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

test2:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 2))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test3:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-100 -n 3))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test5:				$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 5))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test100:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 100))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l

test500:			$(NAME)	
					$(eval ARG = $(shell shuf -i 0-5000 -n 500))
					./push_swap $(ARG) | ./checker_linux $(ARG)
					@echo -n "Instructions: "
					@./push_swap $(ARG) | wc -l