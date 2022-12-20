/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:22:06 by mtravez           #+#    #+#             */
/*   Updated: 2022/12/20 13:09:57 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define TILE_WIDTH 35
#define TILE_LENGTH 35

mlx_image_t *temp_tiles;

void	draw_map(void *mlx, t_map *map)
{
	int	i;

	i = 0;
	mlx_texture_t *texture = mlx_load_png("resources/fence.png");
	temp_tiles = mlx_texture_to_image(mlx, texture);
	while (map->layout[i])
	{
		mlx_image_to_window(mlx, temp_tiles, i * TILE_WIDTH, 0);
		i++;
	}
		// ft_printf("%i, ", i);
		// mlx_image_to_window(mlx, temp_tiles, i * TILE_WIDTH, 50);
}