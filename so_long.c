/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:29:56 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/19 16:17:05 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

mlx_image_t	*g_img;
mlx_image_t	*g_img2;

mlx_image_t *png_to_image(char *path, void *mlx)
{
	mlx_texture_t *texture;
	mlx_image_t *image;

	texture = mlx_load_png(path);
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

t_player	*init_player(void *mlx)
{
	mlx_image_t	**images;
	t_player	*player;

	images = malloc(sizeof(mlx_image_t *) * 4);
	player = malloc(sizeof(t_player *));
	if (!images || !player)
		return (NULL);
	images[0] = png_to_image("resources/BichoRight.png", mlx);
	images[1] = png_to_image("resources/BichoLeft.png", mlx);
	images[2] = png_to_image("resources/BichoFront.png", mlx);
	images[3] = png_to_image("resources/BichoBack.png", mlx);
	player->image = images;
	player->collectibles = 0;
	player->direction = 0;
	return (player);
}

mlx_image_t **init_exit(void *mlx)
{
	mlx_image_t **exit;
	
	exit = malloc(sizeof(mlx_image_t *) * 2);
	if (!exit)
		return (NULL);
	exit[0] = png_to_image("resources/HoleClose.png", mlx);
	exit[1] = png_to_image("resources/HoleOpen.png", mlx);
	return (exit);
}

mlx_image_t **init_map(void *mlx)
{
	mlx_image_t **map_img;

	map_img = malloc(sizeof(mlx_image_t *) * 5);
	if (!map_img)
	return (NULL);
	map_img[0] = png_to_image("resources/grass.png", mlx);
	map_img[1] = png_to_image("resources/fence.png", mlx);
	map_img[2] =png_to_image("resources/fence_v.png", mlx);
	map_img[3] =png_to_image("resources/chicken.png", mlx);
	map_img[4] =png_to_image("resources/bush.png", mlx);
	return (map_img);
}

t_game	*init_game(t_map *map)
{
	t_game	*game;
	
	game = malloc(sizeof(t_game));
	if (!map || !game)
		return(NULL);
	
	game->map = map;
	
	game->mlx = mlx_init(map->width * 32 + 15, map->length * 32 + 15, "my game", true);
	if (!game->mlx)
		return (NULL);
	
	game->player = init_player(game->mlx);
	
	game->exit = init_exit(game->mlx);
	
	game->map_image = init_map(game->mlx);
	if (!game->player || !game->exit || !game->map_image)
		return (NULL);
	
	game->steps = 0;
	
	game->total_col = ft_lstsize(map->coll);
	return (game);
}



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

// void hook2(void *param)
// {
// 	t_game *game = param;
	
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(game->mlx);
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
// 		(game->player->image)->instances[0].y -= 5;
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
// 		(game->player->image)->instances[0].y += 5;
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
// 		(game->player->image)->instances[0].x -= 5;
// 	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
// 		(game->player->image)->instances[0].x += 5;
// }

void	test(mlx_key_data_t keycode, void *param)
{
	t_game *game = param;
	
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

void move(void *param)
{
	t_game *game = param;
	int x = g_img->instances[0].x;
	int y = g_img->instances[0].y;
	
	if (mlx_is_key_down(game->mlx, MLX_KEY_SPACE))
	{
		// texture = mlx_load_png("resources/bicho.png");
		// mlx_draw_texture(g_img, texture, 10, 10);
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
	if(argc != 2 || ft_strlen(argv[1]) < 5 || ft_strncmp(&argv[1][ft_strlen(argv[1] - 4)], ".ber", 5) != 0)
	{
		ft_printf("Invalid path");
		return (0);
	}
	map = get_map(argv[1]);
	
	game = init_game(map);
	if (!game)
		exit (EXIT_FAILURE);
	draw_all(map, game);
	mlx_key_hook(game->mlx, &test, game);
	
	// // Looping and exit
	mlx_loop(game->mlx);  
	mlx_terminate(game->mlx);
	// if (map)
	// 	ft_free_map(map);
	free_game(game);
	return (EXIT_SUCCESS);
	
	// ft_printf("%i", works("map.ber"));
	return(0);
}
