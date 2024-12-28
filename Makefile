NAME = fractol
NAME_BNS = fractol_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lm -O3
RM = rm -f


SRC = mandatory/calc_pixel_color.c mandatory/fill_img.c mandatory/fractol_functions.c mandatory/handle_events.c mandatory/init.c mandatory/main.c mandatory/math_utils.c mandatory/my_utils.c
SRC_BNS = bonus/calc_pixel_color.c bonus/fill_img.c bonus/fractol_functions.c bonus/handle_events.c bonus/init.c bonus/main.c bonus/math_utils.c bonus/my_utils.c

OBJ = $(SRC:.c=.o)
OBJ_BNS = $(SRC_BNS:.c=.o)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) -o $(NAME)

$(NAME_BNS): $(OBJ_BNS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ_BNS) -o $(NAME_BNS)

mandatory/%.o: mandatory/%.c mandatory/fractal.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/fractal.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME_BNS)

clean:
	$(RM) $(OBJ) $(OBJ_BNS)

fclean: clean
	$(RM) $(NAME) $(NAME_BNS)

re: fclean all