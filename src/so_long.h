/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:13:59 by mtravez           #+#    #+#             */
/*   Updated: 2023/02/09 12:39:15 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../lib/libft/libft.h"
# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../map_check/map.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

# define TILE_WIDTH 32
# define TILE_LENGTH 32

enum	e_details
{
	GRASS,
	H_FENCE,
	V_FENCE,
	CHICKEN,
	BUSH
};

enum	e_fox
{
	Z_D,
	Z_I,
	Z_F,
	Z_A
};

enum e_exit
{
	EXIT,
	EXIT_OPEN
};

typedef struct s_player
{
	mlx_image_t	**image;
	int			direction;
	int			collectibles;
}	t_player;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
	mlx_image_t	**map_image;
	t_player	*player;
	mlx_image_t	**exit;
	int			total_col;
	int			steps;
	mlx_image_t	*counter;
}	t_game;

void	*map_error(char *message);

/*This function draws the map*/
void	draw_collectibles(t_map *map, t_game *game);
void	draw_bush(t_map *map, t_game *game);
void	draw_fences(t_map *map, t_game *game);
void	draw_ground(t_map *map, t_game *game);
void	draw_player_and_exit(t_game *game);
void	draw_all(t_map *map, t_game *game);
int		is_correct(t_map **map);
t_map	*get_map(char *path);
void	free_matrix(char **matrix);
void	free_list(t_list *head);
void	ft_free_map(t_map *map);
void	free_game(t_game *game);
void	*ft_lstpop(t_list **list);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
t_game	*init_game(t_map *map);
#endif