/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:22:06 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/19 16:18:29 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define TILE_WIDTH 32
#define TILE_LENGTH 32

void	draw_player_and_exit(t_map *map, t_game *game)
{
	int	exit;

	exit = 0;
	if (game->player->collectibles == game->total_col)
		exit = 1;
	mlx_image_to_window(game->mlx, game->exit[exit], game->map->exit->x * TILE_WIDTH + TILE_WIDTH / 2 \
		, (game->map->exit->y) * TILE_LENGTH + TILE_LENGTH / 2);
	mlx_image_to_window(game->mlx, game->player->image[game->player->direction], (game->map->player->x * TILE_WIDTH) + TILE_WIDTH / 2 \
		, game->map->player->y * TILE_LENGTH + TILE_LENGTH / 2);
}

void	draw_ground(t_map *map, t_game *game)
{
	int	i;
	int j;

	i = 0;
	while (i < map->length)
	{
		j = 0;
		while (j < map->width)
		{
			mlx_image_to_window(game->mlx, game->map_image[GRASS], j * TILE_WIDTH + 10, i * TILE_LENGTH + 10);
			j++;
		}
		i++;
	}
}

void	draw_fences(t_map *map, t_game *game)
{
	int	i;

	i = 1;
	while(i < map->length)
	{
		mlx_image_to_window(game->mlx, game->map_image[V_FENCE], TILE_LENGTH / 2, (i - 1) * TILE_LENGTH + TILE_LENGTH / 2);
		mlx_image_to_window(game->mlx, game->map_image[V_FENCE], map->width * TILE_WIDTH - TILE_WIDTH / 2, (i - 1) * TILE_LENGTH + TILE_LENGTH / 2) ;
		i++;
	}
	
	i = 1;
	while(i < map->width)
	{
		mlx_image_to_window(game->mlx, game->map_image[H_FENCE], ((i - 1) * TILE_WIDTH) + TILE_WIDTH / 2 + 10, TILE_LENGTH / 2);
		mlx_image_to_window(game->mlx, game->map_image[H_FENCE], ((i - 1) * TILE_WIDTH) + TILE_WIDTH / 2 + 10, map->length * TILE_LENGTH - TILE_LENGTH / 2);
		i++;
	}
}

void	draw_bush(t_map *map, t_game *game)
{
	char	c;
	int		i;
	int		j;

	i = 1;
	while (i < map->length - 1)
	{
		j = 1;
		while (j < map->width - 1)
		{
			c = map->layout[i][j];
			if (c == '1')
			{
				mlx_image_to_window(game->mlx, game->map_image[BUSH], (j) * TILE_WIDTH + TILE_WIDTH / 2 \
				, (i - 1) * TILE_LENGTH + TILE_LENGTH);
			}
			j++;
		}
		i++;
	}
}

void	draw_collectibles(t_map *map, t_game *game)
{
	char	c;
	int		i;
	int		j;

	i = 1;
	while (i < map->length - 1)
	{
		j = 1;
		while (j < map->width - 1)
		{
			c = map->layout[i][j];
			if (c == 'C')
			{
				mlx_image_to_window(game->mlx, game->map_image[CHICKEN], j * TILE_WIDTH + TILE_WIDTH / 2 \
				, i * TILE_LENGTH + TILE_LENGTH / 2);
			}
			j++;
		}
		i++;
	}
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
	if (game->map->player->x == game->map->exit->x && game->map->player->y == game->map->exit->y)
		mlx_close_window(game->mlx);
}
