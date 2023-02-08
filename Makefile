# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 19:41:52 by mtravez           #+#    #+#              #
#    Updated: 2023/02/08 12:57:54 by mtravez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = map_check/map.c map_check/extra_functions.c map_check/check.c map_check/struct_functions.c map_check/path_check.c\
src/so_long.c src/errors.c src/draw_map.c src/ft_free_stuff.c src/move_functions.c src/initiation.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -fsanitize=address

LIBFT = ./lib/libft/libft.a

MLX42 = ./lib/MLX42/libmlx42.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX42) $(OBJ)
	@cc $(SRC) $(FLAGS) $(LIBFT) $(MLX42) -lglfw -L "$(shell brew --prefix glfw)/lib/" -o $(NAME)

$(LIBFT):
	@make -C ./lib/libft

$(MLX42):
	@make -C ./lib/MLX42

clean:
	@/bin/rm -f $(OBJ)
	@make clean -C ./lib/libft
	@make clean -C ./lib/MLX42

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C ./lib/libft
	@make fclean -C ./lib/MLX42

re: fclean all 

.PHONY: all clean fclean re