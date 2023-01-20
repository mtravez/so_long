/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:33:55 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/19 16:50:26 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*This function creates an image from a png with its path as a parameter
@param path The path to the png to transfor to mlx image*/
static mlx_image_t	*png_to_image(char *path, void *mlx)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

/*This function initializes the player with an array for the 
images necessary to draw it, the number of collectibles it has
collected and which direction the image is pointing to.*/
static t_player	*init_player(void *mlx)
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

/*This function creates an rray containing the two images necessary 
to draw the exit of the game (exit open and exit closed).*/
static mlx_image_t	**init_exit(void *mlx)
{
	mlx_image_t	**exit;

	exit = malloc(sizeof(mlx_image_t *) * 2);
	if (!exit)
		return (NULL);
	exit[0] = png_to_image("resources/HoleClose.png", mlx);
	exit[1] = png_to_image("resources/HoleOpen.png", mlx);
	return (exit);
}

/*This function creates an array of the images necessary to 
draw the map for the game.*/
static mlx_image_t	**init_map(void *mlx)
{
	mlx_image_t	**map_img;

	map_img = malloc(sizeof(mlx_image_t *) * 5);
	if (!map_img)
		return (NULL);
	map_img[0] = png_to_image("resources/grass.png", mlx);
	map_img[1] = png_to_image("resources/fence.png", mlx);
	map_img[2] = png_to_image("resources/fence_v.png", mlx);
	map_img[3] = png_to_image("resources/chicken.png", mlx);
	map_img[4] = png_to_image("resources/bush.png", mlx);
	return (map_img);
}

/*This function initiates a game with the apropiate images and
data necessary to play the game
@param map the map from which to estract the information to start the game*/
t_game	*init_game(t_map *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!map || !game)
		return (NULL);
	game->map = map;
	game->mlx = mlx_init(map->width * 32 + 15, map->length * 32 + 15, \
		"so_long", true);
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
