/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:22:06 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/13 13:41:24 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define TILE_WIDTH 32
#define TILE_LENGTH 32

mlx_image_t *temp_tiles;
mlx_image_t *player_fox;

void	set_fox(void *mlx, t_map *map)
{
	mlx_texture_t *texture = mlx_load_png("resources/bicho.png");
	player_fox = mlx_texture_to_image(mlx, texture);
	mlx_image_to_window(mlx, player_fox, map->player->x * TILE_WIDTH, map->player->y * TILE_LENGTH);
}

void	draw_map(void *mlx, t_map *map)
{
	int	i;
	int j;

	i = 0;
	mlx_texture_t *texture = mlx_load_png("resources/grass.png");
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
	set_fox(mlx, map);
	i = 0;
	texture = mlx_load_png("resources/fence_v.png");
	temp_tiles = mlx_texture_to_image(mlx, texture);
	while(i < map->length)
	{
		mlx_image_to_window(mlx, temp_tiles, 10, i * TILE_LENGTH);
		mlx_image_to_window(mlx, temp_tiles, map->width * TILE_WIDTH, i * TILE_LENGTH) ;
		i++;
	}
	
	i = 0;
	texture = mlx_load_png("resources/fence.png");
	temp_tiles = mlx_texture_to_image(mlx, texture);
	while(i < map->width)
	{
		mlx_image_to_window(mlx, temp_tiles, i * TILE_WIDTH + 10, 0);
		mlx_image_to_window(mlx, temp_tiles, i * TILE_WIDTH + 10, map->length * TILE_LENGTH);
		i++;
	}
}
