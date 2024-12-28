# CC = cc
# FLAGS = -Wall -Wextra -Werror
# MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lm -O3
# NAME = fractol

# SRC = mandatory/calc_pixel_color.c mandatory/fill_img.c mandatory/fractol_functions.c mandatory/handle_events.c mandatory/init.c mandatory/main.c mandatory/math_utils.c mandatory/my_utils.c
# BNS_SRC = bonus/calc_pixel_color.c bonus/fill_img.c bonus/fractol_functions.c bonus/handle_events.c bonus/init.c bonus/main.c bonus/math_utils.c bonus/my_utils.c

# all: $(NAME)

# $(NAME): $(SRC) mandatory/fractol.h mandatory/events.h
# 	$(CC) $(FLAGS) $(MLX_FLAGS) $(SRC) -o $(NAME)

# clean:
# 	rm -f $(NAME)

# bonus: $(SRC) mandatory/fractol.h mandatory/events.h
# 	$(CC) $(FLAGS) $(MLX_FLAGS) $(SRC) -o fractol_bonus

# fclean: clean

# re: fclean all



CC= cc

FLAGS=-Wall -Wextra -Werror

FILES = Mandelbort.c my_mlx_pixel_put.c scalling.c Equation_fractal.c zoom_.c julia2.c equation_fractal_julia.c zoom_v2.c \
		key_handler.c ft_strcmp.c ft_close.c 
FILES = mandatory/calc_pixel_color.c mandatory/fill_img.c mandatory/fractol_functions.c mandatory/handle_events.c mandatory/init.c mandatory/main.c mandatory/math_utils.c mandatory/my_utils.c

BONUS_MAIN=bonus/bonus_bonus.o
FILES2 = bonus/burnin_ship_bonus.c bonus/keyhandler3_bonus.c bonus/zoom_v3_bonus.c bonus/equation_fractal_3_bonus.c

NAME = fractol

HEADER = fractol.h

NAME_BONUS=fractol_bonus

OBJ = $(FILES:.c=.o)

OBJ2 = $(FILES2:.c=.o)

HEADER = mandatory/fractol.h

.PHONY: all re clean fclean bonus

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -Ofast -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c 
	$(CC) $(FLAGS) -Ofast -Imlx -I . -c $< -o $@

bonus: $(NAME_BONUS) $(HEADER)

$(NAME_BONUS): $(OBJ2) $(OBJ) $(BONUS_MAIN)
	$(CC) $(FLAGS) $(OBJ2) $(OBJ) $(BONUS_MAIN) -Ofast -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ2) $(BONUS_MAIN)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all