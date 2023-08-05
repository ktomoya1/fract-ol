NAME = fractol

SRCS_DIR = ./srcs
SRCS_FILE = main.c \
	calculate_complex_number.c \
	draw_mandelbrot.c

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE))
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = $(SRCS_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

INC_DIR = ./includes

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
DEBUGFLAGS = -g
RM = rm
RMFLAGS = -f

.c.o:
	${CC} ${CFLAGS} -I$(SRCS_DIR)/mlx -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -L$(SRCS_DIR)/mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(RMFLAGS) $(OBJS)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME) $(LIBFT)

re: fclean all

debug: 
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $(OBJS) $(LIBFT) -L$(SRCS_DIR)/mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.PHONY: all clean fclean re debug
