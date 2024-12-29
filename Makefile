NAME = fractol
NAME_BNS = fractol_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -O3
RM = rm -f


SRC = mandatory/calc_pixel_color.c mandatory/fill_img.c mandatory/fractol_functions.c mandatory/handle_events.c mandatory/init.c mandatory/main.c mandatory/math_utils.c mandatory/my_utils.c
SRC_BNS = bonus/calc_pixel_color_bonus.c bonus/fill_img_bonus.c bonus/fractol_functions_bonus.c bonus/handle_events_bonus.c bonus/init_bonus.c bonus/main_bonus.c bonus/math_utils_bonus.c bonus/my_utils_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BNS = $(SRC_BNS:.c=.o)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) -o $(NAME)

$(NAME_BNS): $(OBJ_BNS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ_BNS) -o $(NAME_BNS)

mandatory/%.o: mandatory/%.c mandatory/fractal.h mandatory/events.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/fractal.h bonus/events.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME_BNS)

clean:
	$(RM) $(OBJ) $(OBJ_BNS)

fclean: clean
	$(RM) $(NAME) $(NAME_BNS)

re: fclean all