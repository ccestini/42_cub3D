# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccestini <ccestini@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 10:37:19 by ccestini          #+#    #+#              #
#    Updated: 2023/05/13 10:01:46 by ccestini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D

MLX_DIR		=	./minilibx
MLX_FLAGS	=	-lmlx -lz -framework OpenGL -framework AppKit

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

LFLAGS		= -L $(MLX_DIR) -lmlx

RM			= rm -rf

SRCS		= main.c \
			parse/read_file.c parse/read_file_utils.c \
			parse/get_map.c parse/get_map2.c parse/get_colors.c \
			parse/get_textures.c parse/check_elements.c \
			parse/check_map.c parse/check_map2.c \
			parse/free.c parse/utils.c parse/utils2.c \
			game/game.c game/player.c game/maths.c  game/wall_check.c \
			game/map_slice.c game/draw_utils.c game/moves.c
			

OBJS		= $(SRCS:.c=.o)

all:		$(NAME)
			@printf "\033[32m-> Executable Done! <-\033[0m\n"

libft.a:
			@$(MAKE) all -C libft

$(NAME):	libft.a $(OBJS)
			@$(MAKE) -s -C $(MLX_DIR) all
			@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME) $(LFLAGS) -L ./libft -lft
		

clean:
			@$(RM) $(OBJS)
			@$(MAKE) clean -C libft
			@$(MAKE) -s -C $(MLX_DIR) clean
			@printf "\033[35m-> *.o cleaned! <-\033[0m\n"

fclean:		clean
			@$(RM) $(NAME)
			@$(MAKE) fclean -C libft
			@printf "\033[36m-> executable deleted! <-\033[0m\n"

re:			fclean all

.PHONY:		all clean fclean re

