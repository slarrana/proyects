SRCS = cub3d.c \
		parseo/first_line.c \
		parseo/first_column.c \
		parseo/last_line.c \
		parseo/last_column.c \
		parseo/read.c \
		parseo/pars.c \
		parseo/sky.c \
		parseo/floor.c \
		parseo/variables.c \
		parseo/check_path.c \
		parseo/path.c \
		parseo/perimeter.c \
		parseo/check.c \
		parseo/init.c \
		parseo/start_pos.c \
		parseo/mapping.c \
		raycasting/init.c \
		raycasting/sprite.c \
		raycasting/move.c \
		raycasting/rot.c \
		raycasting/keys.c \
		raycasting/draw.c \
		raycasting/draw_sprite.c \
		raycasting/wall.c \
		raycasting/colision.c \
		raycasting/render_frame.c \
		raycasting/create_bmp.c \
		raycasting/create_img.c

OBJS = $(SRCS:.c=.o)

NAME = cub3D

CC = gcc -Wall -Wextra -Werror

INCLUDE = -I minilibx

MLX_DIR	= minilibx_mms_20200219

all: $(NAME)

$(NAME):	$(OBJS)
	make -C libft
	make -C $(MLX_DIR)
	cp minilibx_mms_20200219/libmlx.dylib libmlx.dylib
	$(CC)  $(OBJS) -o $(NAME) -L libft -lft -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

re: fclean all

clean:
	rm -f $(OBJS)
	make clean -C libft
	make clean -C $(MLX_DIR)
fclean: clean
	rm -f $(NAME)
	make fclean -C libft
	rm -f libmlx.dylib

