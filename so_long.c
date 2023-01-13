/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:29:56 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/13 19:15:05 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

mlx_image_t	*g_img;
mlx_image_t	*g_img2;
mlx_texture_t *texture;

void hook(void *param)
{
	mlx_t *mlx = param;
	
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		g_img->instances[0].x += 5; 
		
}

void hook2(void *param)
{
	mlx_t *mlx = param;
	
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		g_img2->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_img2->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_img2->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_img2->instances[0].x += 5;
}

void move(void *param)
{
	mlx_t *mlx = param;
	int x = g_img->instances[0].x;
	int y = g_img->instances[0].y;
	
	if (mlx_is_key_down(mlx, MLX_KEY_SPACE))
	{
		texture = mlx_load_png("resources/bicho.png");
		mlx_draw_texture(g_img, texture, 10, 10);
		// texture = mlx_load_png("resources/bicho3.png");
		// mlx_draw_texture(g_img, texture, g_img->instances[0].x, g_img->instances[0].y);
		// texture = mlx_load_png("resources/bicho4.png");
		// mlx_draw_texture(g_img, texture, g_img->instances[0].x, g_img->instances[0].y);
		// texture = mlx_load_png("resources/bicho5.png");
		// mlx_draw_texture(g_img, texture, g_img->instances[0].x, g_img->instances[0].y);
		// texture = mlx_load_png("resources/bicho.png");
		// mlx_draw_texture(g_img, texture, g_img->instances[0].x, g_img->instances[0].y);
	}
	// if (g_img->instances[0].x % 15 >= 6)
	// {
	// 	texture = mlx_load_png("resources/bicho2.png");
	// 	mlx_draw_texture(g_img, texture, g_img->instances[0].x, g_img->instances[0].y);
	// }
	// if (g_img->instances[0].x % 31 == 0)
	// {
	// 	texture = mlx_load_png("resources/bicho3.png");
	// 	mlx_draw_texture(g_img, texture, g_img->instances[0].x, g_img->instances[0].y);
	// }
}

// mlx_keyfunc func(void *param)
// {
// 	mlx_t *mlx = param;
	
// 	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(mlx);
// 	if (mlx_is_key_down(mlx, MLX_KEY_W))
// 		g_img->instances[0].y -= 15;
// 	if (mlx_is_key_down(mlx, MLX_KEY_S))
// 		g_img->instances[0].y += 15;
// 	if (mlx_is_key_down(mlx, MLX_KEY_A))
// 		g_img->instances[0].x -= 15;
// 	if (mlx_is_key_down(mlx, MLX_KEY_D))
// 		g_img->instances[0].x += 15;
// }

int main(int argc, char **argv)
{
	mlx_texture_t *texture;
	t_map	*map;
	t_game *game;
	t_player *player;

	// Vorbereitung of MLX
	map = get_map("map.ber");
	game = malloc(sizeof(t_game));
	player = malloc(sizeof(t_player));
	if (!map || !game || !player)
		return(0);
	game->mlx = mlx_init(map->width * 32 + 15, map->length * 32 + 15, "my game", true);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	texture = mlx_load_png(Z_D);
	player->image = mlx_texture_to_image(game->mlx, texture);
	player->collectibles = 0;
	game->steps = 0;
	game->total_col = ft_lstsize(map->coll);
	game->player = player;
	
	draw_all(game->mlx, map);
	
	// Zorrito
	// texture = mlx_load_png("resources/bicho.png");
	// g_img = mlx_texture_to_image(mlx, texture);
	// mlx_image_to_window(mlx, g_img, 0, 0);
	// mlx_loop_hook(mlx, &hook, mlx);
	// mlx_loop_hook(mlx, &move, mlx);
	
	// Fence
	// texture = mlx_load_png("resources/fence.png");
	// g_img2 = mlx_texture_to_image(mlx, texture);
	// mlx_image_to_window(mlx, g_img2, 90, 90);
	// mlx_loop_hook(mlx, &hook2, mlx);
	
	// Looping and exit
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
	
	ft_printf("%i", works("map.ber"));
	return(0);
}
