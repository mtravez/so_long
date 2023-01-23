/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:29:56 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/23 14:29:01 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*This function takes the key input of the user and runs a 
function depending of which key was pressed.*/
void	key_function(mlx_key_data_t keycode, void *param)
{
	t_game	*game;

	game = param;
	if (keycode.key == MLX_KEY_LEFT && keycode.action == 1)
		move_left(game);
	if (keycode.key == MLX_KEY_RIGHT && keycode.action == 1)
		move_right(game);
	if (keycode.key == MLX_KEY_UP && keycode.action == 1)
		move_up(game);
	if (keycode.key == MLX_KEY_DOWN && keycode.action == 1)
		move_down(game);
	if (keycode.key == MLX_KEY_ESCAPE && keycode.action == 1)
		mlx_close_window(game->mlx);
	if (game->map->player->x == game->map->exit->x \
	&& game->map->player->y == game->map->exit->y)
		mlx_close_window(game->mlx);
}

/*This function draws the map, player, exit and collectibles in
order so it will look correct. For the bonus part, it also writes
how many pases the player has taken in the upper corner of the map.*/
void	draw_all(t_map *map, t_game *game)
{
	char	*str;

	draw_ground(map, game);
	draw_bush(map, game);
	draw_player_and_exit(game);
	draw_collectibles(map, game);
	draw_fences(map, game);
	str = ft_itoa(game->steps);
	mlx_put_string(game->mlx, str, game->mlx->width - 35, 10);
	free(str);
}

int	main(int argc, char **argv)
{
	t_map			*map;
	t_game			*game;

	if (argc != 2 || ft_strlen(argv[1]) < 5 || \
	ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 5) != 0)
	{
		ft_printf("Error\nInvalid path");
		return (EXIT_FAILURE);
	}
	map = get_map(argv[1]);
	if (!map)
		return (EXIT_FAILURE);
	game = init_game(map);
	if (!game)
		exit (EXIT_FAILURE);
	draw_all(map, game);
	mlx_key_hook(game->mlx, &key_function, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	free_game(game);
	return (EXIT_SUCCESS);
}
