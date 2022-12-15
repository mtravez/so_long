/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:29:56 by mtravez           #+#    #+#             */
/*   Updated: 2022/12/14 16:27:32 by mtravez          ###   ########.fr       */
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
		texture = mlx_load_png("resources/bicho5.png");
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

int main(int argc, char **argv)
{
	// mlx_t	*mlx;
	// mlx_texture_t *texture;

	// // Vorbereitung of MLX
	// mlx = mlx_init(300, 300, "testing", true);
	// if (!mlx)
	// 	exit(EXIT_FAILURE);

	// // Zorrito
	// texture = mlx_load_png("resources/bicho.png");
	// g_img = mlx_texture_to_image(mlx, texture);
	// // ft_printf("height: %i, width: %i", g_img->height, g_img->width);
	// mlx_image_to_window(mlx, g_img, 0, 0);
	// mlx_loop_hook(mlx, &move, mlx);
	// mlx_loop_hook(mlx, &hook, mlx);
	
	// // Fence
	// texture = mlx_load_png("resources/fence.png");
	// g_img2 = mlx_texture_to_image(mlx, texture);
	// mlx_image_to_window(mlx, g_img2, 90, 90);
	// mlx_loop_hook(mlx, &hook2, mlx);
	
	// // Looping and exit
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	// return (EXIT_SUCCESS);
	
	ft_printf("%i", works("map.ber"));
	return(0);
}