FILES =	drawline.c main.c read_file.c utils.c
SOURCES_DIRECTORY = src/
SRC			= $(addprefix $(SOURCES_DIRECTORY), $(FILES))
OBJ			= $(SRC:.c=.o)

NAME		= fdf
HEADER		= ./include/fdf.h
LIBFT		= Libft/libft.a
MLX42		= MLX42/build/libmlx42.a
CFLAGS		= -Wall -Wextra -Werror -Iinclude -lglfw -L"/Users/ashevchu/.brew/opt/glfw/lib/"

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADER) $(LIBFT) $(MLX42)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX42) -o $(NAME)

%.o: %.c
	cc $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C Libft

clean:
			rm -f $(OBJ)
			make clean -C Libft

fclean:		clean
			rm -rf $(NAME)
			make fclean -C Libft

re:			fclean $(NAME)

.PHONY:		all clean fclean re