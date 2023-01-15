/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtravez <mtravez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:13:59 by mtravez           #+#    #+#             */
/*   Updated: 2023/01/15 15:28:55 by mtravez          ###   ########.fr       */
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

#define H_FENCE "resources/fence.png"
#define V_FENCE "resources/fence_v.png"
#define GRASS "resources/grass.png"
#define BUSH "resources/bush.png"
#define CHICKEN "resources/chicken.png"
#define EXIT "resources/chest.png"
#define Z_D "resources/bicho.png"

typedef struct s_player
{
	mlx_image_t *image;
	int	collectibles;
}	t_player;

typedef struct s_game
{
	void *mlx;
	t_player *player;
	int total_col;
	int steps;
}	t_game;

void	map_error(char *message);
void	draw_all(void *mlx, t_map *map);
void	draw_map(void *mlx, t_map *map);
int		is_correct(t_map **map);
t_map	*get_map(char *path);
void	free_matrix(char **matrix);
void	free_list(t_list *head);
void	ft_free_map(t_map *map);
void	*ft_lstpop(t_list **list);
#endif