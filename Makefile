# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amiguel- <amiguel-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 10:25:56 by amiguel-          #+#    #+#              #
#    Updated: 2024/02/29 16:19:22 by amiguel-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
FLAGS = -Wall -Wextra -Werror -g3 # -fsanitize=address
C = gcc

SRC = init_map.c	\
					detect_path.c	\
					check_map.c	\
					init_win.c \
					movement.c \
					change_sprites.c \
					game.c \
					player.c \
					print_sprites.c \
					push_sprites.c \
					main.c 
SRC_DIR = ./src
#BONUS = read_map_bonus.c utils_bonus.c so_long_bonus.c check_path_bonus.c \
#		print_game_bonus.c e_hooks_bonus.c steps_screen_bonus.c \
#		utils2_bonus.c
#BONUS_DIR = ./src/bonus
OBJS = $(addprefix $(SRC_DIR)/, $(SRC:.c=.o))
#BONUS_OBJS = $(addprefix $(BONUS_DIR)/, $(BONUS:.c=.o))
#B_NAME = so_long_bonus
RM = rm -rf

#INCLUDE = -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = ./libft/
LIBFT_A = libft.a
LIBFT = -L$(LIBFT_DIR) $(LIBFT_DIR)$(LIBFT_A)

MLX_PATH = mlx/
MINILIBX:= -L $(MLX_PATH) $(MLX_PATH)libmlx.a -lmlx -framework OpenGL -framework AppKit

GREEN='\033[32m'
GRAY='\033[2;37m'
NONE='\033[0m'

all: $(NAME)
	@echo " \033[36m[ OK ] | READY TO PLAY!\033[0m"

.SILENT: $(OBJS)
$(NAME): $(OBJS)
	@echo " \033[33m[ .. ] | Compiling minilibx..\033[0m"
	@make -C $(MLX_PATH)
	@echo $(CURSIVE)$(GREEN) " - Making libft..." $(NONE)
# @sleep 3
	@make -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(GREEN) " - Compiling $(NAME)" $(NONE)
	@gcc $(FLAGS) $(OBJS) $(MINILIBX) $(LIBFT) -o $(NAME)
# @sleep 3
	@echo $(CURSIVE)$(GREEN) " - Compiled" $(NONE)

B = .

#prueba

.SILENT: $(BONUS_OBJS)
$(B_NAME): $(BONUS_OBJS)
	@echo " \033[33m[ .. ] | Compiling minilibx..\033[0m"
	@make -C $(MLX_PATH)
	@echo $(CURSIVE)$(GREEN) " - Making libft..." $(NONE)
	@sleep 3
	@make bonus -C $(LIBFT_DIR)
	@echo $(CURSIVE)$(GREEN) " - Compiling $(B_NAME)" $(NONE)
	@gcc $(FLAGS) $(BONUS_OBJS) $(MINILIBX) $(LIBFT) -o $(B_NAME)
	@sleep 3
	@echo $(CURSIVE)$(GREEN) " - Compiled" $(NONE)

#prueba finalizada

bonus: $(B)

$(B): $(B_NAME)
	
		
clean:
	$(RM) $(OBJS) $(BONUS_OBJS) $(LIBFT_A)
fclean: clean
	@echo $(CURSIVE)$(GREEN) " - Removing $(NAME)..." $(NONE)
	@sleep 1
	@$(RM) $(NAME) $(B_NAME) $(BONUS_OBJS) $(OBJS)
	@make -C $(LIBFT_DIR) fclean
	@echo $(CURSIVE)$(GREEN) " - Clean!" $(NONE)
re: fclean
	@sleep 2
	@echo $(CURSIVE)$(GREEN) " - Compiling again..." $(NONE)
	@sleep 3
	@make all


.PHONY: all fclean clean re