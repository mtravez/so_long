/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:47:15 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/23 14:24:57 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move(t_game *game, char c)
{
	if (c == '1')
		return (0);
	if (c == 'E' && game->player->collectibles != game->total_col)
		return (0);
	return (1);
}

/*This function checks the player's position in the map and whether
the left adjacent cell is neither a wall or the exit (if not all
collectibles have been aquired yet). It the changes the player's
position on the map and redraws it with the left-view image of the fox*/
void	move_left(t_game *game)
{
	char	c;
	int		redraw;

	redraw = 1;
	if (game->map->player->x - 1 >= 0)
		c = game->map->layout[game->map->player->y][game->map->player->x - 1];
	else
		return ;
	if (!can_move(game, c))
		return ;
	if (c == 'C')
		game->player->collectibles++;
	if (game->player->direction == Z_I && c != 'C')
		redraw = 0;
	game->map->layout[game->map->player->y][game->map->player->x - 1] = 'P';
	game->map->layout[game->map->player->y][game->map->player->x] = '0';
	game->map->player->x -= 1;
	game->steps++;
	game->player->direction = Z_I;
	if (redraw)
		draw_all(game->map, game);
	else
		game->player->image[game->player->direction]->instances[game->player-> \
		image[game->player->direction]->count - 1].x -= TILE_WIDTH;
	ft_printf("steps: %i\n", game->steps);
}

/*This function checks the player's position in the map and whether
the right adjacent cell is neither a wall or the exit (if not all
collectibles have been aquired yet). It the changes the player's
position on the map and redraws it with the right-view image of the fox*/
void	move_right(t_game *game)
{
	char	c;
	int		redraw;

	redraw = 1;
	if (game->map->player->x + 1 <= game->map->width)
		c = game->map->layout[game->map->player->y][game->map->player->x + 1];
	else
		return ;
	if (!can_move(game, c))
		return ;
	if (c == 'C')
		game->player->collectibles++;
	if (game->player->direction == Z_D && c != 'C')
		redraw = 0;
	game->map->layout[game->map->player->y][game->map->player->x + 1] = 'P';
	game->map->layout[game->map->player->y][game->map->player->x] = '0';
	game->map->player->x += 1;
	game->steps++;
	game->player->direction = Z_D;
	if (redraw)
		draw_all(game->map, game);
	else
		game->player->image[game->player->direction]->instances[game->player-> \
		image[game->player->direction]->count - 1].x += TILE_WIDTH;
	ft_printf("steps: %i\n", game->steps);
}

/*This function checks the player's position in the map and whether
the upper adjacent cell is neither a wall or the exit (if not all
collectibles have been aquired yet). It the changes the player's
position on the map and redraws it with the back-view image of the fox*/
void	move_up(t_game *game)
{
	char	c;
	int		redraw;

	redraw = 1;
	if (game->map->player->y - 1 >= 0)
		c = game->map->layout[game->map->player->y - 1][game->map->player->x];
	else
		return ;
	if (!can_move(game, c))
		return ;
	if (c == 'C')
		game->player->collectibles++;
	if (game->player->direction == Z_A && c != 'C')
		redraw = 0;
	game->map->layout[game->map->player->y - 1][game->map->player->x] = 'P';
	game->map->layout[game->map->player->y][game->map->player->x] = '0';
	game->map->player->y -= 1;
	game->steps++;
	game->player->direction = Z_A;
	if (redraw)
		draw_all(game->map, game);
	else
		game->player->image[game->player->direction]->instances[game->player-> \
		image[game->player->direction]->count - 1].y -= TILE_LENGTH;
	ft_printf("steps: %i\n", game->steps);
}

/*This function checks the player's position in the map and whether
the lower adjacent cell is neither a wall or the exit (if not all
collectibles have been aquired yet). It the changes the player's
position on the map and redraws it with the front-view image of the fox*/
void	move_down(t_game *game)
{
	char	c;
	int		redraw;

	redraw = 1;
	if (game->map->player->y + 1 <= game->map->length)
		c = game->map->layout[game->map->player->y + 1][game->map->player->x];
	else
		return ;
	if (!can_move(game, c))
		return ;
	if (c == 'C')
		game->player->collectibles++;
	if (game->player->direction == Z_F && c != 'C')
		redraw = 0;
	game->map->layout[game->map->player->y + 1][game->map->player->x] = 'P';
	game->map->layout[game->map->player->y][game->map->player->x] = '0';
	game->map->player->y += 1;
	game->steps++;
	game->player->direction = Z_F;
	if (redraw)
		draw_all(game->map, game);
	else
		game->player->image[game->player->direction]->instances[game->player-> \
		image[game->player->direction]->count - 1].y += TILE_LENGTH;
	ft_printf("steps: %i\n", game->steps);
}
