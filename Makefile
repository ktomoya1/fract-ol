NAME = fractol

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
DEBUGFLAGS = -g
RM = rm
RMFLAGS = -f

INC_DIR = ./includes

SRCS = main.c

OBJS = $(SRCS:.c=.o)

SRCS_DIR = ./srcs
LIBFT = $(SRCS_DIR)/libft.a

.c.o:
	${CC} ${CFLAGS} -Imlx -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(SRCS_DIR)

debug: 
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(OBJS) $(LIBFT) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) fclean -C $(SRCS_DIR)
	$(RM) $(RMFLAGS) $(OBJS)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
