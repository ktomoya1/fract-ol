NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)
DEBUGFLAGS = -g3 -O0 -fsanitize=address
RM = rm
RMFLAGS = -f

INC_DIR = ./includes

SRCS = main.c

OBJS = $(SRCS:.c=.o)

SRCS_DIR = ./srcs
LIBFT = $(SRCS_DIR)/libft.a

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(SRCS_DIR)

debug: 
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(SRCS) $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) fclean -C $(SRCS_DIR)
	$(RM) $(RMFLAGS) $(OBJS)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
