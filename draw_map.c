/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:22:06 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/13 15:36:16 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define TILE_WIDTH 32
#define TILE_LENGTH 32

mlx_image_t *temp_tiles;
mlx_image_t *player_fox;

void	set_player_and_exit(void *mlx, t_map *map)
{
	mlx_texture_t *texture = mlx_load_png("resources/bicho.png");
	player_fox = mlx_texture_to_image(mlx, texture);
	mlx_image_to_window(mlx, player_fox, map->player->x * TILE_WIDTH, map->player->y * TILE_LENGTH);
	texture = mlx_load_png(EXIT);
	temp_tiles = mlx_texture_to_image(mlx, texture);
	mlx_image_to_window(mlx, temp_tiles, map->exit->x * TILE_WIDTH, map->exit->y * TILE_LENGTH);
}

void	draw_map(void *mlx, t_map *map)
{
	int	i;
	int j;

	i = 0;
	mlx_texture_t *texture = mlx_load_png(GRASS);
	temp_tiles = mlx_texture_to_image(mlx, texture);
	while (i < map->length)
	{
		j = 0;
		while (j < map->width)
		{
			mlx_image_to_window(mlx, temp_tiles, j * TILE_WIDTH + 10, i * TILE_LENGTH + 10);
			j++;
		}
		i++;
	}
	i = 0;
	texture = mlx_load_png(V_FENCE);
	temp_tiles = mlx_texture_to_image(mlx, texture);
	while(i < map->length)
	{
		mlx_image_to_window(mlx, temp_tiles, 10, i * TILE_LENGTH);
		mlx_image_to_window(mlx, temp_tiles, map->width * TILE_WIDTH, i * TILE_LENGTH) ;
		i++;
	}
	
	i = 0;
	texture = mlx_load_png(H_FENCE);
	temp_tiles = mlx_texture_to_image(mlx, texture);
	while(i < map->width)
	{
		mlx_image_to_window(mlx, temp_tiles, i * TILE_WIDTH + 10, 0);
		mlx_image_to_window(mlx, temp_tiles, i * TILE_WIDTH + 10, map->length * TILE_LENGTH);
		i++;
	}
}

void	draw_all(void *mlx, t_map *map)
{
	char	c;
	int		i;
	int		j;

	draw_map(mlx, map);
	i = 1;
	while (i < map->length - 1)
	{
		j = 1;
		while (j < map->width - 1)
		{
			c = map->layout[i][j];
			if (c == '1')
			{
				mlx_texture_t *texture = mlx_load_png(BUSH);
				temp_tiles = mlx_texture_to_image(mlx, texture);
				mlx_image_to_window(mlx, temp_tiles, j * TILE_WIDTH, i * TILE_LENGTH);
			}
			if (c == 'C')
			{
				mlx_texture_t *texture = mlx_load_png(CHICKEN);
				temp_tiles = mlx_texture_to_image(mlx, texture);
				mlx_image_to_window(mlx, temp_tiles, j * TILE_WIDTH, i * TILE_LENGTH);
			}
			j++;
		}
		i++;
	}
	set_player_and_exit(mlx, map);
}