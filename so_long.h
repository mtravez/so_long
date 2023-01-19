/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:13:59 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/19 16:08:55 by mtravez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include "maps/map.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

#define GRASS 0
#define H_FENCE 1
#define V_FENCE 2
#define CHICKEN 3
#define BUSH 4
#define EXIT 0
#define EXIT_OPEN 1
#define Z_D 0
#define Z_I 1
#define Z_F 2
#define Z_A 3

typedef struct s_player
{
	mlx_image_t **image;
	int direction;
	int	collectibles;
}	t_player;

typedef struct s_game
{
	mlx_t *mlx;
	t_map *map;
	mlx_image_t	**map_image;
	t_player *player;
	mlx_image_t	**exit;
	int total_col;
	int steps;
}	t_game;

void	map_error(char *message);
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
#endif