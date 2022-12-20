# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 19:41:52 by mtravez           #+#    #+#              #
#    Updated: 2022/12/20 19:46:58 by mtravez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long.a

SRC=so_long.c errors.c maps/map.c maps/extra_functions.c maps/check.c draw_map.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C MLX42
	@cc $(OBJ) libft/libft.a MLX42/libmlx42.a -I include -lglfw -L "/Users/mtravez/.brew/opt/glfw/lib/"
	@ar rc $(NAME) $(OBJ) 

clean:
	@/bin/rm -f $(OBJ)
	make clean -C libft
	make clean -C MLX42

fclean: clean
	@/bin/rm -f $(NAME) a.out
	make fclean -C libft
	make fclean -C MLX42

re: fclean all