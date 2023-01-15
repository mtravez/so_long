/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:22:06 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/15 20:25:29 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define TILE_WIDTH 32
#define TILE_LENGTH 32

mlx_image_t *temp_tiles;

void	draw_player_and_exit(t_map *map, t_game *game)
{
	mlx_image_to_window(game->mlx, game->player->image, (map->player->x * TILE_WIDTH) + TILE_WIDTH / 2 \
		, map->player->y * TILE_LENGTH + TILE_LENGTH / 2);
	mlx_image_to_window(game->mlx, game->exit, map->exit->x * TILE_WIDTH + TILE_WIDTH / 2 \
		, (map->exit->y) * TILE_LENGTH + TILE_LENGTH / 2);
}

void	draw_ground(t_map *map, t_game *game)
{
	int	i;
	int j;
	mlx_texture_t *texture;

	i = 0;
	texture = mlx_load_png(GRASS);
	temp_tiles = mlx_texture_to_image(game->mlx, texture);
	while (i < map->length)
	{
		j = 0;
		while (j < map->width)
		{
			mlx_image_to_window(game->mlx, temp_tiles, j * TILE_WIDTH + 10, i * TILE_LENGTH + 10);
			j++;
		}
		i++;
	}
}

void	draw_fences(t_map *map, t_game *game)
{
	int	i;
	mlx_texture_t *texture;

	i = 1;
	texture = mlx_load_png(V_FENCE);
	temp_tiles = mlx_texture_to_image(game->mlx, texture);
	while(i < map->length)
	{
		mlx_image_to_window(game->mlx, temp_tiles, TILE_LENGTH / 2, (i - 1) * TILE_LENGTH + TILE_LENGTH / 2);
		mlx_image_to_window(game->mlx, temp_tiles, map->width * TILE_WIDTH - TILE_WIDTH / 2, (i - 1) * TILE_LENGTH + TILE_LENGTH / 2) ;
		i++;
	}
	
	i = 1;
	texture = mlx_load_png(H_FENCE);
	temp_tiles = mlx_texture_to_image(game->mlx, texture);
	while(i < map->width)
	{
		mlx_image_to_window(game->mlx, temp_tiles, ((i - 1) * TILE_WIDTH) + TILE_WIDTH / 2 + 10, TILE_LENGTH / 2);
		mlx_image_to_window(game->mlx, temp_tiles, ((i - 1) * TILE_WIDTH) + TILE_WIDTH / 2 + 10, map->length * TILE_LENGTH - TILE_LENGTH / 2);
		i++;
	}
}

void	draw_bush(t_map *map, t_game *game)
{
	char	c;
	int		i;
	int		j;
	mlx_texture_t *texture;

	i = 1;
	while (i < map->length - 1)
	{
		j = 1;
		while (j < map->width - 1)
		{
			c = map->layout[i][j];
			if (c == '1')
			{
				texture = mlx_load_png(BUSH);
				temp_tiles = mlx_texture_to_image(game->mlx, texture);
				mlx_image_to_window(game->mlx, temp_tiles, (j) * TILE_WIDTH + TILE_WIDTH / 2 \
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
				mlx_texture_t *texture = mlx_load_png(CHICKEN);
				temp_tiles = mlx_texture_to_image(game->mlx, texture);
				mlx_image_to_window(game->mlx, temp_tiles, j * TILE_WIDTH + TILE_WIDTH / 2 \
				, i * TILE_LENGTH + TILE_LENGTH / 2);
			}
			j++;
		}
		i++;
	}
}

void	draw_all(t_map *map, t_game *game)
{
	draw_ground(map, game);
	draw_bush(map, game);
	draw_player_and_exit(map, game);
	draw_collectibles(map, game);
	draw_fences(map, game);
}
