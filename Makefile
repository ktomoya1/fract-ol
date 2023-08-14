NAME = fractol

SRCS_DIR = ./srcs
SRCS_FILE = fractol.c \
	draw_fractal.c \
	fractol_utils.c \
	event_handler.c \
	calculate_complex.c \
	ft_atof.c \

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILE))
OBJS = $(SRCS:.c=.o)

LIBFT_DIR = $(SRCS_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = $(SRCS_DIR)/mlx

INC_DIR = ./includes

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)
DEBUGFLAGS = -g
RM = rm
RMFLAGS = -f

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

ifeq ($(MAKECMDGOALS), debug)
CFLAGS += -g3 -O0
endif

debug: re

.PHONY: all clean fclean re debug
