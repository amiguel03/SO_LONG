# Nombre del programa de salida
NAME = so_long

# Norma de compilación
CC = gcc

# Flags de compilación
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

# Fuentes .c
SRCS =	so_long.c \
		error.c \
		split.c \
		strlen_row_col.c \
		substr.c \
		init_map.c \
		count_objs.c \
		flood.c \
		init_mlx.c \
		open_map.c \
		window.c \
		print_sprites.c \
		movement.c \
		putnbr.c

SRC_DIR = ./src
# Ruta a la mlx

MLX = ./mlx/libmlx.a

# Normas que convierten los .c en .o
OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

# Regla principal para construir el programa principal
all: $(NAME)

$(NAME): $(OBJS) $(MLX)
	$(CC) $(OBJS) -fsanitize=address -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

# Regla para compilar archivos .c en objetos .o
%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

# REgla MLX

$(MLX) :
	make -C ./mlx

# Regla para limpiar archivos objeto (.o)
clean:
	rm -f *.o
	$(RM) $(OBJS)
	make clean -C ./mlx

# Regla para limpiar archivos objeto y el programa de salida
fclean: clean
	@$(RM) $(NAME) $(OBJS)

# Regla para limpiar y reconstruir todo
re: fclean all

# Indica que estas reglas no corresponden a archivos reales
.PHONY : clean fclean re #bonus
