# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 19:41:52 by mtravez           #+#    #+#              #
#    Updated: 2023/01/17 18:47:46 by mtravez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long.a

SRC=so_long.c errors.c maps/map.c maps/extra_functions.c maps/check.c maps/struct_functions.c draw_map.c ft_free_stuff.c move_functions.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C MLX42
	@cc $(OBJ) -fsanitize=address libft/libft.a MLX42/libmlx42.a -I include -lglfw -L "/Users/mtravez/.brew/opt/glfw/lib/"
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