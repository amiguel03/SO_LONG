# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 10:25:56 by amiguel-          #+#    #+#              #
#    Updated: 2024/02/14 12:07:32 by amiguel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME
NAME = so_long

# LIBRARIES AND FRAMEWORKS
LIBFT			= libft/libft.a
MLX				= mlx/libmlx.a #= -Lmlx -lmlx
FRAMEWORKS		= -framework OpenGL -framework AppKit
# -Lmlx -lmlx -> La opción -Lmlx especifica dónde encontrar la biblioteca
# y -lmlx especifica la biblioteca en sí que debe ser enlazada.

# SOURCE FILES
SRC_DIR			=	src/
SRC_FILES		= 	main.c	\
					init.c
SRC				=	$(addprefix $(SRC_DIR), $(SRC_FILES))

# OBJECT FILES
OBJ_DIR			= objs/
OBJ_FILES 		= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# COMPILER OPTIONS
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -g -O3
INCLUDE = -I includes
RM		= rm -rf

# COLORS
RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
BLUE	=	\033[94;1m
PINK	=	\033[95;1m
CLEAR	=	\033[0m

# MAKEFILE RULES
all:	$(NAME)

$(NAME):	$(OBJ_FILES)
	@echo "\n$(BLUE)Compiling libft and MinilibX.$(CLEAR)"
	@make -sC libft
	@echo "$(GREEN)[libft --> OK]$(CLEAR)"
	@make -sC mlx
	@echo "$(GREEN)[MiniLibX --> OK]\n$(CLEAR)"
	@echo "$(BLUE)Compiling the FDF program.$(CLEAR)"
	$(CC) $(FLAGS) $(INCLUDE) $(LIBFT) $(MLX) $(FRAMEWORKS) $(OBJ_FILES) -o $(NAME)
	@echo "$(GREEN)[So_Long --> OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)\n"
#@echo "$(PINK)\tUsage: ./fdf <path_map>$(CLEAR)\n"


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	@echo "$(BLUE)Removing compiled files.$(CLEAR)"
	@make clean -sC libft
	@make clean -sC mlx
	$(RM) $(OBJ_DIR)
	@echo "$(GREEN)Object files removed correctly\n$(CLEAR)"

fclean: clean
	@make fclean -sC libft
	@echo "$(BLUE)Removing exec. files.$(CLEAR)"
	$(RM) $(NAME)
	@echo "$(GREEN)Object files and binary removed correctly\n$(CLEAR)"

re: fclean all

.PHONY:		all clean fclean re

###########################################################################################

r: run
run: all
	./$(NAME)