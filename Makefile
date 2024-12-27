CC = cc
FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lm -O3
NAME = fractol

SRC = mandatory/calc_pixel_color.c mandatory/fill_img.c mandatory/fractol_functions.c mandatory/handle_events.c mandatory/init.c mandatory/main.c mandatory/math_utils.c mandatory/my_utils.c
BNS_SRC = bonus/calc_pixel_color.c bonus/fill_img.c bonus/fractol_functions.c bonus/handle_events.c bonus/init.c bonus/main.c bonus/math_utils.c bonus/my_utils.c

all: $(NAME)

$(NAME): $(SRC) mandatory/fractol.h mandatory/events.h
	$(CC) $(FLAGS) $(MLX_FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

bonus: $(SRC) mandatory/fractol.h mandatory/events.h
	$(CC) $(FLAGS) $(MLX_FLAGS) $(SRC) -o fractol_bonus

fclean: clean

re: fclean all