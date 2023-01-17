/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:47:15 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/17 19:03:01 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_game *game)
{
	char	c;
	mlx_texture_t *texture;

	if (game->map->player->x - 1 >= 0)
		c = game->map->layout[game->map->player->y][game->map->player->x - 1];
	else
		return ;
	if (c == '1')
		return ;
	if (c == 'E' && game->player->collectibles != game->total_col)
		return ;
	if (c == 'C')
		game->player->collectibles++;
	game->map->layout[game->map->player->y][game->map->player->x - 1] = 'P';
	game->map->layout[game->map->player->y][game->map->player->x] = '0';
	game->map->player->x -= 1;
	game->steps++;
	texture = mlx_load_png("resources/BichoLeft.png");
	game->player->image = mlx_texture_to_image(game->mlx, texture);
	draw_all(game->map, game);
}

void	move_right(t_game *game)
{
	char	c;
	mlx_texture_t *texture;

	if (game->map->player->x + 1 <= game->map->width)
		c = game->map->layout[game->map->player->y][game->map->player->x + 1];
	else
		return ;
	if (c == '1')
		return ;
	if (c == 'E' && game->player->collectibles != game->total_col)
		return ;
	if (c == 'C')
		game->player->collectibles++;
	game->map->layout[game->map->player->y][game->map->player->x + 1] = 'P';
	game->map->layout[game->map->player->y][game->map->player->x] = '0';
	game->map->player->x += 1;
	game->steps++;
	texture = mlx_load_png("resources/BichoRight.png");
	game->player->image = mlx_texture_to_image(game->mlx, texture);
	draw_all(game->map, game);
}

void	move_up(t_game *game)
{
	char	c;
	mlx_texture_t *texture;

	if (game->map->player->y - 1 >= 0)
		c = game->map->layout[game->map->player->y - 1][game->map->player->x];
	else
		return ;
	if (c == '1')
		return ;
	if (c == 'E' && game->player->collectibles != game->total_col)
		return ;
	if (c == 'C')
		game->player->collectibles++;
	game->map->layout[game->map->player->y - 1][game->map->player->x] = 'P';
	game->map->layout[game->map->player->y][game->map->player->x] = '0';
	game->map->player->y -= 1;
	game->steps++;
	texture = mlx_load_png("resources/BichoBack.png");
	game->player->image = mlx_texture_to_image(game->mlx, texture);
	draw_all(game->map, game);
}

void	move_down(t_game *game)
{
	char	c;
	mlx_texture_t *texture;

	if (game->map->player->y + 1 <= game->map->length)
		c = game->map->layout[game->map->player->y + 1][game->map->player->x];
	else
		return ;
	if (c == '1')
		return ;
	if (c == 'E' && game->player->collectibles != game->total_col)
		return ;
	if (c == 'C')
		game->player->collectibles++;
	game->map->layout[game->map->player->y + 1][game->map->player->x] = 'P';
	game->map->layout[game->map->player->y][game->map->player->x] = '0';
	game->map->player->y += 1;
	game->steps++;
	texture = mlx_load_png("resources/BichoFront.png");
	game->player->image = mlx_texture_to_image(game->mlx, texture);
	draw_all(game->map, game);
}
