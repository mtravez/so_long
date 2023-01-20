/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:29:56 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/20 15:56:46 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}

void	draw_all(t_map *map, t_game *game)
{
	char	*str;

	draw_ground(map, game);
	draw_bush(map, game);
	draw_player_and_exit(map, game);
	draw_collectibles(map, game);
	draw_fences(map, game);
	str = ft_itoa(game->steps);
	mlx_put_string(game->mlx, str, game->mlx->width - 35, 10);
	free(str);
	if (game->map->player->x == game->map->exit->x \
	&& game->map->player->y == game->map->exit->y)
		mlx_close_window(game->mlx);
}

int	main(int argc, char **argv)
{
	mlx_texture_t	*texture;
	t_map			*map;
	t_game			*game;
	t_player		*player;

	if (argc != 2 || ft_strlen(argv[1]) < 5 || \
	ft_strncmp(&argv[1][ft_strlen(argv[1] - 4)], ".ber", 5) != 0)
	{
		ft_printf("Invalid path");
		return (0);
	}
	map = get_map(argv[1]);
	if (!map)
	{
		system("leaks a.out");
		return (EXIT_FAILURE);
	}
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
